--- src/external/cpuid/platform/src/platform/config.hpp.orig	2024-11-05 10:07:15 UTC
+++ src/external/cpuid/platform/src/platform/config.hpp
@@ -11,7 +11,7 @@
 // http://sourceforge.net/p/predef/wiki/Architectures/
 
 // Detect operating systems
-#if defined(__linux__)
+#if defined(__linux__) || defined(__FreeBSD__)
 #define PLATFORM_LINUX 1
 #if defined(__ANDROID__)
 #define PLATFORM_ANDROID 1
