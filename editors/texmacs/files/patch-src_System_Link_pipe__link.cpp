--- src/System/Link/pipe_link.cpp.orig	2014-03-03 11:44:14 UTC
+++ src/System/Link/pipe_link.cpp
@@ -30,7 +30,7 @@
 #include <signal.h>
 #include <sys/wait.h>
 #endif
-#ifndef __APPLE__
+#if !defined(__APPLE__) && !defined(__FreeBSD__)
 #include <malloc.h>
 #endif
 
