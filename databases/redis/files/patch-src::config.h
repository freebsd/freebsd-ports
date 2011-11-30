--- src/config.h.orig	2011-11-30 16:28:05.000000000 +0400
+++ src/config.h	2011-11-30 16:28:19.000000000 +0400
@@ -25,7 +25,7 @@
 #endif
 
 /* Test for backtrace() */
-#if defined(__APPLE__) || defined(__linux__)
+#if defined(__APPLE__) || defined(__linux__) || defined(__FreeBSD__)
 #define HAVE_BACKTRACE 1
 #endif
 
