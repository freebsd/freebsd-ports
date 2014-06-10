--- src/common/config.h.orig	2014-04-01 22:24:54.000000000 +0400
+++ src/common/config.h	2014-06-10 14:49:32.000000000 +0400
@@ -25,7 +25,7 @@
 #if defined(WIN32) || defined(_WIN32)
 #	define LOVE_WINDOWS 1
 #endif
-#if defined(linux) || defined(__linux) || defined(__linux__)
+#if defined(linux) || defined(__linux) || defined(__linux__) || defined(__FreeBSD__)
 #	define LOVE_LINUX 1
 #endif
 #if defined(__APPLE__)
