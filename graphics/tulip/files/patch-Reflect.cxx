--- library/tulip/include/tulip/cxx/Reflect.cxx.orig	Fri Dec  6 21:39:53 2002
+++ library/tulip/include/tulip/cxx/Reflect.cxx	Fri Oct 29 14:14:08 2004
@@ -29,7 +29,7 @@
 template<typename T> bool DataSet::getAndFree(const std::string &str,T& value) {
   if (get(str,value)) {
     delete ((T*)(data[str].value));
-    data.remove(str);
+    data.erase(str);
     return true;
   }
   else
