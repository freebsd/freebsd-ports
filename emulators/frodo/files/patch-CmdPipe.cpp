--- CmdPipe.cpp.orig	2002-01-02 21:19:34 UTC
+++ CmdPipe.cpp
@@ -17,9 +17,11 @@ extern "C" {
 	#include <string.h>
 	#include <signal.h>
 
+#if !defined(__FreeBSD__)
 #if defined(__alpha__)
 	#include <cma.h>
 #endif
+#endif
 
 #if defined(AIX)
 	#include <sys/select.h>
@@ -30,6 +32,9 @@ extern "C" {
 #if defined(__linux__)
 	#include <sys/time.h>
 #endif
+#if defined(__FreeBSD__)
+	#include <sys/time.h>
+#endif
 
 	#include <time.h>
 	#include <errno.h>
