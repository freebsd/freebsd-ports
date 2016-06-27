--- src/include/common.h.orig	2016-05-28 05:15:40 UTC
+++ src/include/common.h
@@ -8,13 +8,19 @@
     #include <CL/cl.hpp>
 #endif
 
+#ifdef __FreeBSD__
+    #include <sys/types.h>
+#endif
+
 #include <stdlib.h>
 #include <chrono>
 #include <string>
 
 #define TAB             "  "
 #define NEWLINE         "\n"
+#ifndef __FreeBSD__
 #define uint            unsigned int
+#endif
 
 #define MAX(X, Y)       \
     (X > Y)? X: Y;
@@ -41,6 +47,8 @@
     #elif defined(__arm__)
         #define OS_NAME     "Linux ARM"
     #endif
+#elif defined(__FreeBSD__)
+    #define OS_NAME         "FreeBSD"
 #endif
 
 
