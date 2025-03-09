--- src/host/premake.h.orig	2025-03-08 19:35:32 UTC
+++ src/host/premake.h
@@ -72,6 +72,10 @@
 #define PLATFORM_ARCHITECTURE "loongarch64"
 #elif defined(__e2k__)
 #define PLATFORM_ARCHITECTURE "e2k"
+#elif defined(__powerpc64__)
+#define PLATFORM_ARCHITECTURE "PPC64"
+#elif defined(__powerpc__)
+#define PLATFORM_ARCHITECTURE "PPC"
 #elif !defined(RC_INVOKED)
 #error Unknown architecture detected
 #endif
