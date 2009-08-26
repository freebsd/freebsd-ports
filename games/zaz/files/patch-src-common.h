--- src/common.h.orig	2009-08-21 02:53:16.000000000 +0400
+++ src/common.h	2009-08-25 19:01:52.000000000 +0400
@@ -26,11 +26,12 @@
 #ifdef WIN32
 #include <windows.h>
 #include <direct.h>
-typedef unsigned int uint;
-typedef unsigned long ulong;
 #pragma warning(disable:4996)
 #endif
 
+typedef unsigned int uint;
+typedef unsigned long ulong;
+
 #include <cmath>
 #include <cstdio>
 #include <cstdlib>
