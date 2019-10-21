--- runtime/flangrti/mpmalloc.c.orig	2019-10-09 20:28:35 UTC
+++ runtime/flangrti/mpmalloc.c
@@ -17,7 +17,7 @@
 
 /* mp-safe wrappers for malloc, etc. */
 
-#ifdef TARGET_LINUX
+#if defined TARGET_LINUX && !defined(__FreeBSD__)
 #include <features.h>
 #endif
 
