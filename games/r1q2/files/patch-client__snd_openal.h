--- client/snd_openal.h.orig	Mon Dec  5 21:03:34 2005
+++ client/snd_openal.h	Thu May 18 20:09:05 2006
@@ -3,7 +3,6 @@
 #ifdef USE_OPENAL
 #include <AL/al.h>
 #include <AL/alc.h>
-#include <AL/altypes.h>
 
 #include "client.h"
 
@@ -14,7 +13,7 @@
 #ifdef _WIN32
 #include "../win32/alw_win.h"
 #endif
-#ifdef __linux__
+#ifdef __unix__
 #include "../linux/al_linux.h"
 #endif
 #endif
@@ -158,7 +157,7 @@
 #define ALimp_Shutdown					ALW_Shutdown
 
 #else
-#ifdef __linux__
+#ifdef __unix__
 
 #define AL_DRIVER_OPENAL	"/usr/lib/libopenal.so"
 
