--- ./snd_openal.h.orig	Thu May 19 17:56:13 2005
+++ ./snd_openal.h	Sun Feb 26 11:23:56 2006
@@ -18,7 +18,7 @@
 #ifdef _WIN32
 #include "alw_win.h"
 #endif
-#ifdef __linux__
+#if defined(__linux__) || defined(__FreeBSD__)
 #include "al_linux.h"
 #endif
 #endif
@@ -162,9 +162,9 @@
 #define ALimp_Shutdown					ALW_Shutdown
 
 #else
-#ifdef __linux__
+#if defined(__linux__) || defined(__FreeBSD__)
 
-#define AL_DRIVER_OPENAL	"/usr/lib/libopenal.so"
+#define AL_DRIVER_OPENAL	"libopenal.so"
 
 #define ALimp_Init						AL_Init
 #define ALimp_Shutdown					AL_Shutdown
