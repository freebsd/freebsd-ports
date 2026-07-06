--- include/renderdoc_app.h.orig	2026-05-01 23:38:47 UTC
+++ include/renderdoc_app.h
@@ -35,7 +35,7 @@
 
 #if defined(WIN32)
 #define RENDERDOC_CC __cdecl
-#elif defined(__linux__)
+#elif defined(__linux__) || defined(__FreeBSD__) || defined(__DragonFly__)
 #define RENDERDOC_CC
 #elif defined(__APPLE__)
 #define RENDERDOC_CC
