--- third_party/dawn/src/common/Platform.h.orig	2021-07-15 19:15:43 UTC
+++ third_party/dawn/src/common/Platform.h
@@ -45,6 +45,11 @@
 #    define DAWN_PLATFORM_EMSCRIPTEN 1
 #    define DAWN_PLATFORM_POSIX 1
 
+#elif defined(__FreeBSD__)
+#    define DAWN_PLATFORM_FREEBSD 1
+#    define DAWN_PLATFORM_LINUX 1
+#    define DAWN_PLATFORM_POSIX 1
+
 #else
 #    error "Unsupported platform."
 #endif
