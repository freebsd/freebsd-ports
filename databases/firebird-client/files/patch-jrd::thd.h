--- jrd/thd.h.orig	Sat Mar  2 00:16:31 2002
+++ jrd/thd.h	Mon May 13 19:10:37 2002
@@ -98,6 +98,11 @@
 #define MULTI_THREAD		1
 #endif
 
+#if (defined(FREEBSD) && defined(SUPERSERVER))
+#define POSIX_THREADS		1
+#define MULTI_THREAD		1
+#endif
+
 #ifdef VMS
 #ifndef GATEWAY
 #define MULTI_THREAD		1
