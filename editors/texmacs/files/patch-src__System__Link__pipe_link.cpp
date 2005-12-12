--- src/System/Link/pipe_link.cpp.orig	Sat Dec  3 03:08:13 2005
+++ src/System/Link/pipe_link.cpp	Mon Dec  5 17:29:15 2005
@@ -23,7 +23,7 @@
 #ifdef OS_WIN32
 #include <sys/pipe.h>
 #endif
-#ifndef __APPLE__
+#if !defined(__APPLE__) && !defined(__FreeBSD__)
 #include <malloc.h>
 #endif
 
