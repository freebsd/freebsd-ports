--- CmdPipe.cpp.orig	Wed Jan  2 22:19:34 2002
+++ CmdPipe.cpp	Fri Sep  5 21:13:34 2003
@@ -17,9 +17,11 @@
 	#include <string.h>
 	#include <signal.h>
 
+#if !defined(__FreeBSD__)
 #if defined(__alpha__)
 	#include <cma.h>
 #endif
+#endif
 
 #if defined(AIX)
 	#include <sys/select.h>
@@ -28,6 +30,9 @@
 #endif
 
 #if defined(__linux__)
+	#include <sys/time.h>
+#endif
+#if defined(__FreeBSD__)
 	#include <sys/time.h>
 #endif
 
