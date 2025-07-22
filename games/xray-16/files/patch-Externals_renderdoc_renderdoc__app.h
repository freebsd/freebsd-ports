--- Externals/renderdoc/renderdoc_app.h.orig	2024-06-17 15:09:40 UTC
+++ Externals/renderdoc/renderdoc_app.h
@@ -39,6 +39,8 @@
 #define RENDERDOC_CC
 #elif defined(__APPLE__)
 #define RENDERDOC_CC
+#elif defined (__FreeBSD__)
+#define RENDERDOC_CC
 #else
 #error "Unknown platform"
 #endif
