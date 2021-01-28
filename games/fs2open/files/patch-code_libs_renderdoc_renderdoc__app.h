--- code/libs/renderdoc/renderdoc_app.h.orig	2021-01-27 17:07:03 UTC
+++ code/libs/renderdoc/renderdoc_app.h
@@ -43,6 +43,8 @@
 #define RENDERDOC_CC
 #elif defined(SCP_SOLARIS)
 #define RENDERDOC_CC
+#elif defined(__FreeBSD__)
+#define RENDERDOC_CC
 #else
 #error "Unknown platform"
 #endif
