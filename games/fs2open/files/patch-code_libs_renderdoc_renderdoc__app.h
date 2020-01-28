--- code/libs/renderdoc/renderdoc_app.h.orig	2020-01-28 14:50:19 UTC
+++ code/libs/renderdoc/renderdoc_app.h
@@ -39,6 +39,8 @@
 #define RENDERDOC_CC
 #elif defined(__APPLE__)
 #define RENDERDOC_CC
+#elif defined(__FreeBSD__)
+#define RENDERDOC_CC
 #else
 #error "Unknown platform"
 #endif
