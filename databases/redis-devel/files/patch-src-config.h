--- src/config.h.orig	2013-02-11 21:47:44.000000000 +0400
+++ src/config.h	2013-02-11 21:50:10.000000000 +0400
@@ -54,7 +54,7 @@
 #endif
 
 /* Test for backtrace() */
-#if defined(__APPLE__) || defined(__linux__)
+#if defined(__APPLE__) || defined(__linux__) || defined(__FreeBSD__)
 #define HAVE_BACKTRACE 1
 #endif
 
