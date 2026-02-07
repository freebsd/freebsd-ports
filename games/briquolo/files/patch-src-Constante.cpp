--- ./src/Constante.cpp.orig	2008-03-22 10:40:33.000000000 +0100
+++ ./src/Constante.cpp	2018-01-29 22:09:08.069039000 +0100
@@ -32,6 +32,7 @@
 #define WIN32_LEAN_AND_MEAN
 #include <windows.h>
 #else
+#include <cstdlib>
 #include <unistd.h>
 #endif
 
@@ -102,7 +103,7 @@
 #else
 
   string dir1(getenv("HOME"));
-  string dir2("/."PACKAGE);
+  string dir2("/." PACKAGE);
   _Local=dir1+dir2;
 
   _NumVersion=VERSION;
