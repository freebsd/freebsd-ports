
$FreeBSD$

--- CmdPipe.cpp.orig	Wed Aug  6 20:56:26 1997
+++ CmdPipe.cpp	Sat Nov 30 01:29:18 2002
@@ -9,16 +9,18 @@
 
 
 extern "C" {
-	#include <string.h>
+	#include <stdlib.h>
 	#include <unistd.h>
 	#include <sys/wait.h>
 	#include <sys/types.h>
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
 
