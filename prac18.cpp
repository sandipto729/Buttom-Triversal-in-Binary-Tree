#include<iostream>
#include<queue>
#include<deque>
using namespace std;
class Node{
    public:
    int data;
    Node*left,*right;
    Node(int val){
        this->data=val;
        this->left=NULL;
        this->right=NULL;
    }
};

Node* makingTree(Node*root){
    int data;
    cout<<"Enter data ";
    cin>>data;
    root=new Node(data);
    if(data==-1)return NULL;
    cout<<"Enter data left of "<<data;
    root->left=makingTree(root->left);
    cout<<"Enter datya right of "<<data;
    root->right=makingTree(root->right);
    return root;
}
vector<int> leftView(Node*root){
    vector<int>ans;
    queue<Node*>qu;
    qu.push(root);
    while(!qu.empty()){
        int size=qu.size();
       // vector<int>res(size);
        for(int i=0;i<size;i++){
            Node*temp=qu.front();
            qu.pop();
            if(i==0)ans.push_back(temp->data);
            if(temp->left)qu.push(temp->left);
            if(temp->right)qu.push(temp->right);
        }
    }
    return ans;
}
int main(){
    Node*root=NULL;
    root=makingTree(root);
    vector<int>ans=leftView(root);
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
}