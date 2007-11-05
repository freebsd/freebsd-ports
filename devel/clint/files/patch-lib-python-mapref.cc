--- lib/python/mapref.cc.orig	2007-11-03 16:16:58.000000000 +0100
+++ lib/python/mapref.cc	2007-11-03 16:17:25.000000000 +0100
@@ -2,7 +2,7 @@
 
 namespace python {
    template <class T>
-      mapref<T>::mapref<T> (MapBase<T>& map, const std::string& k)
+      mapref<T>::mapref (MapBase<T>& map, const std::string& k)
       : s(map), the_item() 
       {
          key = String(k);
@@ -10,7 +10,7 @@
       }; 
 
    template <class T>
-      mapref<T>::mapref<T> (MapBase<T>& map, const Object& k)
+      mapref<T>::mapref (MapBase<T>& map, const Object& k)
       : s(map), key(k), the_item() 
       {
          if(map.hasKey(key)) the_item = map.getItem(key);
