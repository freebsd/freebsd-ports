--- CmdPipe.cpp.orig	Wed Aug  6 20:56:26 1997
+++ CmdPipe.cpp	Sat Mar 10 19:19:59 2001
@@ -16,9 +16,11 @@
 	#include <string.h>
 	#include <signal.h>
 
+#if ! defined(__FreeBSD__)
 #if defined(__alpha__)
 	#include <cma.h>
 #endif
+#endif
 
 #if defined(AIX)
 	#include <sys/select.h>
@@ -27,6 +29,9 @@
 #endif
 
 #if defined(__linux__)
+	#include <sys/time.h>
+#endif
+#if defined(__FreeBSD__)
 	#include <sys/time.h>
 #endif
 
