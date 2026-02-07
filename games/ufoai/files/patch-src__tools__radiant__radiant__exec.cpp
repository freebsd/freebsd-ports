--- ./src/tools/radiant/radiant/exec.cpp.orig	2014-06-05 06:18:39.000000000 +0200
+++ ./src/tools/radiant/radiant/exec.cpp	2014-08-07 16:49:53.703302732 +0200
@@ -28,6 +28,8 @@
 
 #if defined (__FreeBSD__) || defined(__OpenBSD__)
 # include <signal.h>
+# include <sys/types.h>
+# include <sys/wait.h>
 #elif defined(__linux__)
 # include <sys/wait.h>
 #endif
