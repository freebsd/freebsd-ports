--- global.h.orig	Fri Apr  7 01:23:42 1995
+++ global.h	Fri Nov 17 21:27:09 2000
@@ -70,7 +70,7 @@
 #define alloca __builtin_alloca
 #endif
 
-#ifndef __alpha
+#if !defined(__alpha) && !defined(__FreeBSD__)
 #ifndef MAXPATHLEN
 #define MAXPATHLEN 1024
 #endif
