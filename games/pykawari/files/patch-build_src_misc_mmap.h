--- build/src/misc/mmap.h.orig	Thu Jan 30 04:19:12 2003
+++ build/src/misc/mmap.h	Wed Jun  1 00:35:09 2005
@@ -27,7 +27,7 @@
 		// 2001/12/16 suikyo@yk.rim.or.jp : imortal entry bug
 //		if(it==end()) it=insert(pair<KeyType,DataType>(key,DataType()));
 //		if(it==upper_bound(key)) it=insert(pair<const KeyType,DataType>(key,DataType()));
-		if(it==upper_bound(key)) it=insert(TMMap::value_type(key,DataType()));
+		if(it==upper_bound(key)) it=insert(typename TMMap::value_type(key,DataType()));
 		return((*it).second);
 	}
 /*
@@ -42,7 +42,7 @@
 	void Add(const KeyType& key,const DataType& data)
 	{
 //		insert(pair<const KeyType,DataType>(key,data));
-		insert(TMMap::value_type(key,data));
+		insert(typename TMMap::value_type(key,data));
 	}
 
 };
