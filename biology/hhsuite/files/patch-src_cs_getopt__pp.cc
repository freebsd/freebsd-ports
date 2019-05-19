--- src/cs/getopt_pp.cc.orig	2019-05-19 05:36:03 UTC
+++ src/cs/getopt_pp.cc
@@ -21,7 +21,7 @@
 #include <unistd.h>
 #include "getopt_pp.h"
 
-#ifdef __APPLE__
+#if defined(__APPLE__) || defined(__FreeBSD__)
 extern char** environ;
 #endif
 
