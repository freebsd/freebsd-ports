--- ./scrext.c.orig	2010-08-05 08:24:33.000000000 +0200
+++ ./scrext.c	2014-04-21 21:45:57.464501296 +0200
@@ -153,6 +153,13 @@
 #include "lualib.h"
 #include "lauxlib.h"
 
+#ifdef LUA_VERSION_NUM
+# if (LUA_VERSION_NUM >= 502)
+#undef lua_objlen
+#define lua_objlen lua_rawlen
+# endif
+#endif
+
 #define SERVVAR      "_serv_"            // global variable name for server resources
 #define ITERVAR      "_iter_"            // global variable name for iterator
 #define MRMAPVAR     "_mrmap_"           // global variable name for mapreduce mapper
