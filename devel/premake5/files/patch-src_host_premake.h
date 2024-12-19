--- src/host/premake.h.orig	2024-12-11 10:29:35 UTC
+++ src/host/premake.h
@@ -60,6 +60,10 @@
 #elif defined(__arm__) || defined(__thumb__) || defined(__TARGET_ARCH_ARM) || defined(__TARGET_ARCH_THUMB) || \
     defined(__ARM) || defined(_M_ARM) || defined(_M_ARM_T) || defined(__ARM_ARCH)
 #define PLATFORM_ARCHITECTURE "ARM"
+#elif defined(__powerpc64__)
+#define PLATFORM_ARCHITECTURE "PPC64"
+#elif defined(__powerpc__)
+#define PLATFORM_ARCHITECTURE "PPC"
 #endif
 
 /* Pull in platform-specific headers required by built-in functions */
