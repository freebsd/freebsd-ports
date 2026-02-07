--- global.h.orig	1995-04-06 16:23:42 UTC
+++ global.h
@@ -70,7 +70,7 @@
 #define alloca __builtin_alloca
 #endif
 
-#ifndef __alpha
+#if !defined(__alpha) && !defined(__FreeBSD__)
 #ifndef MAXPATHLEN
 #define MAXPATHLEN 1024
 #endif
