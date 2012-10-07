--- ./Sources/Core/System/Unix/init_linux.cpp.orig	2011-01-13 06:15:25.000000000 -0500
+++ ./Sources/Core/System/Unix/init_linux.cpp	2012-10-07 17:20:55.000000000 -0400
@@ -39,6 +39,7 @@
 #include <cstdio>
 #include <cstdlib>
 #include <cstring>
+#include <climits>
 #include "init_linux.h"
 // note: this cannot be replaced by <ctime>! (timeval needs to be defined)
 #include <sys/time.h>
@@ -110,7 +111,7 @@
 
 #else
 #ifndef PROC_EXE_PATH
-#define PROC_EXE_PATH "/proc/self/exe"
+#define PROC_EXE_PATH "/proc/curproc/file"
 #endif
 	int size;
 	struct stat sb;
