--- kqueue.c.orig	Thu Apr 15 01:48:55 2004
+++ kqueue.c	Thu Apr 15 01:49:09 2004
@@ -56,7 +56,7 @@
 #define log_error	warn
 #endif
 
-#if defined(HAVE_INTTYPES_H) && !defined(__OpenBSD__)
+#if defined(HAVE_INTTYPES_H) && !defined(__OpenBSD__) && !defined(__FreeBSD__)
 #define INTPTR(x)	(intptr_t)x
 #else
 #define INTPTR(x)	x
