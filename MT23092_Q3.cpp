#include<iostream>
using namespace std;
struct p{
    int value;
    int priority;
};
void insert(p arr[],int value, int priority,int& size){
  int i=size-1;
  while(i>=0 && arr[i].priority>priority){
    arr[i+1]=arr[i];
    i--;
  }
  arr[i+1].value=value;
  arr[i+1].priority=priority;
  size++;
}
int Find(p arr[],int value,int size){
  for(int i=0;i<size;i++){
    if(arr[i].value==value){
      return arr[i].priority;
    }
  }
  return -1;
}
void Delete(p arr[],int value,int& size){
  int index=-1;
  for(int i=0;i<size;i++){
    if(arr[i].value==value){
      index=i;
      break;
    }
  }
  if(index!=-1){
    for(int i=index;i<size-1;i++){
      arr[i]=arr[i+1];
    }
    cout<<"Element with value "<< value<<" and priority"<<arr[index].priority<<" deleted."<<endl;
  }else{
    cout<<"Element with value "<<value <<" not found "<<endl;
  }
}
void Pop(p arr[],int& size){
  if(size>0){
    cout<<"Element with value" <<arr[0].value<< " and maximum priority ="<<arr[0].priority<<" popped "<<endl;
    for(int i=0;i<size-1;i++){
      arr[i]=arr[i+1];
    }
    size--;
  }
}

int main(){
  const int MAX=100;
  p arr[MAX];
  int size=0;
  char choice= 'Y';
  while(choice =='Y'){
    cout<<"Which operation do you want to perform: 1:Insert, 2:Find, 3:Delete, 4:Pop :"<<endl;
    int operation;
    cin>>operation;
    if(operation==1){
          int value;
          int priority;
          cout<<"Please enter the value,priority to be inserted by separating space"<<endl;
          cin>>value>>priority;
          insert(arr,value,priority,size);
        }
   else if(operation==2){
         cout<<"Please enter the value to be searched:"<<endl;
         int value;
         cin>>value;
         int priority=Find(arr,value,size);
         if(priority!=-1){
           cout<<"value = "<<value<<" is found with priority :"<<priority<<endl;
         }else{
           cout<<"value = "<<value<<" is not found"<<endl;
         }
       }
    else if(operation==3){
        cout<<"Please enter the value to be deleted"<<endl;
        int value;
        cin>>value;
        Delete(arr,value,size);
      }
    else if(operation==4){
       Pop(arr,size);
    }
    cout<<"Do you want to perform more operations? Enter Y or N : ";
    cin>>choice;
  }
  cout<<"Program ended. "<<size<<" element remaining in the queue."<<endl;
  for(int i=0;i<size;i++){
    cout<<"{"<<arr[i].value<<" "<<arr[i].priority<<"}"<<" "<<endl;
  }
  cout<<size;
}
