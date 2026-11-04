--- doctest/parts/public/platform.h.orig	2026-07-06 21:58:29 UTC
+++ doctest/parts/public/platform.h
@@ -20,6 +20,9 @@
 #elif defined(__wasi__)
 #define DOCTEST_PLATFORM_WASI
 
+#elif defined(__FreeBSD__)
+#define DOCTEST_PLATFORM_FREEBSD
+
 #else // defined(linux) || defined(__linux) // defined(__linux__)
 #define DOCTEST_PLATFORM_LINUX
 #endif // DOCTEST_PLATFORM
