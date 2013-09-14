--- src/debug.cpp.orig	2006-02-14 07:57:01.000000000 +0300
+++ src/debug.cpp	2013-09-14 06:53:30.679226734 +0400
@@ -1,8 +1,11 @@
 #ifdef WIN32
   #include <windows.h>
+#else
+  #include "unistd.h"
 #endif
 
 #include "debug.h"
+#include <cstdlib>
 
 
 namespace audiere {
