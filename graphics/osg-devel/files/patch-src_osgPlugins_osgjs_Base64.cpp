--- src/osgPlugins/osgjs/Base64.cpp.orig	2019-10-09 12:52:54 UTC
+++ src/osgPlugins/osgjs/Base64.cpp
@@ -18,7 +18,7 @@ namespace base64
   const char* to_table_end =
     _to_table + sizeof(_to_table);
 
-  const char _from_table[128] =
+  const signed char _from_table[128] =
   {
     -1, -1, -1, -1, -1, -1, -1, -1, // 0
     -1, -1, -1, -1, -1, -1, -1, -1, // 8
@@ -37,6 +37,6 @@ namespace base64
     41, 42, 43, 44, 45, 46, 47, 48, // 112
     49, 50, 51, -1, -1, -1, -1, -1  // 120
   };
-  const char* from_table = _from_table;
+  const signed char* from_table = _from_table;
 }
 
