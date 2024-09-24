- workaround for https://github.com/Yoshimi/yoshimi/issues/208

--- src/Misc/Util.h.orig	2024-09-24 04:50:23 UTC
+++ src/Misc/Util.h
@@ -21,14 +21,10 @@
 #ifndef UTIL_H
 #define UTIL_H
 
+#include <set>
 #include <string>
 
 namespace std {// forward declarations to avoid pervasive includes
-
-  template<typename T>
-  class allocator;
-  template<typename K, typename CMP, class ALLO>
-  class set;
 
   template<typename IT, typename V>
   IT find (IT, IT, V const&);
