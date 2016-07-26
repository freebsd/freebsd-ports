--- src/debug.cpp.orig	2006-02-14 04:57:01 UTC
+++ src/debug.cpp
@@ -1,8 +1,11 @@
 #ifdef WIN32
   #include <windows.h>
+#else
+  #include "unistd.h"
 #endif
 
 #include "debug.h"
+#include <cstdlib>
 
 
 namespace audiere {
