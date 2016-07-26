--- src/DeviceManager.cpp.orig	2016-07-26 13:34:06 UTC
+++ src/DeviceManager.cpp
@@ -6,7 +6,7 @@
 
 ******************************************************************/
 
-#include "portaudio.h"
+#include "../lib-src/portaudio-v19/include/portaudio.h"
 #ifdef __WXMSW__
 #include "pa_win_wasapi.h"
 #endif
