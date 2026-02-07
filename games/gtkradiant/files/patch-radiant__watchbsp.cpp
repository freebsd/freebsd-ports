--- ./radiant/watchbsp.cpp.orig	Thu Mar 16 16:09:46 2006
+++ ./radiant/watchbsp.cpp	Thu Mar 16 16:09:46 2006
@@ -614,7 +614,7 @@
 #if defined(WIN32)
 #define ENGINE_ATTRIBUTE "engine_win32"
 #define MP_ENGINE_ATTRIBUTE "mp_engine_win32"
-#elif defined(__linux__)
+#elif defined(__linux__) || defined(__FreeBSD__)
 #define ENGINE_ATTRIBUTE "engine_linux"
 #define MP_ENGINE_ATTRIBUTE "mp_engine_linux"
 #elif defined(__APPLE__)
