//关联容器实现能快速查找（ O(log n) 复杂度）的数据结构。
//map / set是用红黑树实现的，所以它不允许key值相同的数据插入
//multimap/multiset，它们允许key值相同的数据插入。
#include<map>
#include<set>
#include<string>
#include<iostream>

int main()
{
	//map
	std::map<std::string, int>  m;
	m["a"] = 1;
	m["b"] = 2;
	m["c"] = 3;
	m["a"] = 4;
	std::map<std::string, int>::iterator it;
	for (it = m.begin(); it != m.end(); ++it)
		std::cout << "key: " << it->first << " value: " << it->second << std::endl;//1会被覆盖，打印4 2 3

	//multimap
	std::multimap<int,std::string>  multimap1;
	multimap1.insert(std::multimap<int, std::string>::value_type(1, "One"));
	multimap1.insert(std::multimap<int, std::string>::value_type(1, "One"));
	multimap1.insert(std::multimap<int, std::string>::value_type(2, "Two"));
	std::multimap<int, std::string>::iterator it2;
	for (it2 = multimap1.begin(); it2 != multimap1.end(); it2++)
		std::cout << "key: " << it2->first << " value: " << it2->second << std::endl;

	//set
	std::set<int> s;
	s.insert(1);
	s.insert(2);
	s.insert(1);
	s.insert(3);
	s.insert(1);
	std::cout << "set 中 1 出现的次数是 ：" << s.count(1) << std::endl;//count在set中没有意义，一个键值在set只可能出现0或1次
	std::cout << "set 中 4 出现的次数是 ：" << s.count(4) << std::endl;



	return   0;
}

