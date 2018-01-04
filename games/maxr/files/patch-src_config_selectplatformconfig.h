--- src/config/selectplatformconfig.h.orig	2016-06-03 22:11:14 UTC
+++ src/config/selectplatformconfig.h
@@ -19,7 +19,7 @@
 
 #ifndef MAXR_PLATFORM_CONFIG
 
-#if (defined(linux) || defined(__linux) || defined(__linux__) || defined(__GNU__) || defined(__GLIBC__)) && !defined(_CRAYC)
+#if (defined(linux) || defined(__linux) || defined(__linux__) || defined(__GNU__) || defined(__GLIBC__) || defined(__FreeBSD__)) && !defined(_CRAYC)
 #   define MAXR_PLATFORM_CONFIG "config/platform/linux.h"
 #elif defined(__CYGWIN__)
 #   define MAXR_PLATFORM_CONFIG "config/platform/cygwin.h"
