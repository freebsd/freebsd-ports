--- ./build/src/misc/mmap.h.orig	2009-03-02 17:17:28.000000000 +0100
+++ ./build/src/misc/mmap.h	2009-03-02 17:17:37.000000000 +0100
@@ -24,11 +24,11 @@
 	{
 //		iterator it=lower_bound(key);
 //		std::multimap<KeyType,DataType>::iterator it;
-		typename std::multimap<KeyType, DataType>::iterator it=lower_bound(key);
+		typename std::multimap<KeyType, DataType>::iterator it=std::multimap<KeyType, DataType>::lower_bound(key);
 		// 2001/12/16 suikyo@yk.rim.or.jp : imortal entry bug
 //		if(it==end()) it=insert(pair<KeyType,DataType>(key,DataType()));
 //		if(it==upper_bound(key)) it=insert(pair<const KeyType,DataType>(key,DataType()));
-		if(it==upper_bound(key)) it=insert(typename TMMap<KeyType,DataType>::value_type(key,DataType()));
+		if(it==std::multimap<KeyType, DataType>::upper_bound(key)) it=insert(typename TMMap<KeyType,DataType>::value_type(key,DataType()));
 		return((*it).second);
 	}
 /*
