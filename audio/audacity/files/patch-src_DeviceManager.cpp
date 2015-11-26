--- src/DeviceManager.cpp.orig	2015-07-11 10:02:22 UTC
+++ src/DeviceManager.cpp
@@ -6,7 +6,7 @@
 
 ******************************************************************/
 
-#include "portaudio.h"
+#include "../lib-src/portaudio-v19/include/portaudio.h"
 #ifdef __WXMSW__
 #include "pa_win_wasapi.h"
 #endif
