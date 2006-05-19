--- ./src/dzipmain.c.orig	Tue Nov  1 14:54:40 2005
+++ ./src/dzipmain.c	Tue May 16 17:36:22 2006
@@ -5,7 +5,7 @@
 #include <sys/utime.h>
 #endif
 
-#ifdef __linux__
+#ifdef __unix__
 #include <errno.h>
 #endif
 
