--- src/config.h.orig	2012-02-24 16:56:36.000000000 +0400
+++ src/config.h	2012-02-24 16:57:01.000000000 +0400
@@ -25,7 +25,7 @@
 #endif
 
 /* Test for backtrace() */
-#if defined(__APPLE__) || defined(__linux__) || defined(__sun)
+#if defined(__APPLE__) || defined(__linux__) || defined(__sun) || defined(__FreeBSD__)
 #define HAVE_BACKTRACE 1
 #endif
 
