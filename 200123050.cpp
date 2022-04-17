#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int N;
int Pages;
struct Page
{
	Page* next;
	Page* prev;
	int capacity;
	int n;
	vector<int> keys;
};
int lookup(vector<int> keys,int key)
{
	int i = 0;
	while(i<keys.size())
	{
		if(keys[i]==key)
			return i;
		++i;
	}
	return -1;
}
Page* newPage()
{
	Page* t = new Page();
	t->next =  NULL;
	t->prev = NULL;
	t->capacity = N - 16;
	t->n = 0;
	Pages++;
	return t;
}
void addPage(Page* location,int Space,int key)
{
	location->capacity = location->capacity-4-Space;
	location->keys.push_back(key);
	location->n = location->n + 1;
	return;
}
void insert(Page* &root,int Space,int key)
{
	if(root==NULL)
		root = newPage();
	Page* t = root;
	while(t->next!=NULL&&(t->capacity)-4<Space)
		t = t->next;
	if((t->capacity-4)>=Space)
		addPage(t,Space,key);
	else
	{
		Page* x = newPage();
		x->prev = t;
		t->next = x;
		addPage(x,Space,key); 
	}
	return;
}
void search(Page* root,int key)
{
	
	while(root!=NULL)
	{
		int i = 0;
		int k = lookup(root->keys,key);
		if(k!=-1)
		{
			cout<<i<<" "<<k<<endl;
			return;
		}
		root = root->next;
		++i;
	}
	cout<<"-1 -1"<<endl;
	return;
}
void display(Page* root)
{
	cout<<Pages<<" ";
	while(root!=NULL)
	{
		cout<<root->n<<" ";
		root = root->next;
	}
	cout<<endl;
	return;
}
int main()
{
	cin>>N;
	Pages = 0;
	Page* root = NULL;
	while(true)
	{
		int x;
		cin>>x;
		if(x==1)
		{
			int Space,key;
			cin>>Space>>key;
			insert(root,Space,key);
		}
		else if(x==2)
			display(root);
		else if(x==3)
		{
			int key;
			cin>>key;
			search(root,key);
		}
		else
			break;
	}
	return 0;
}
