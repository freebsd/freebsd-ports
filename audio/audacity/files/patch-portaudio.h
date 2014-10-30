diff -ur lib-src/portmixer/include/portmixer.h lib-src/portmixer/include/portmixer.h
--- lib-src/portmixer/include/portmixer.h	2014-09-22 13:38:13.000000000 -0700
+++ lib-src/portmixer/include/portmixer.h	2014-10-01 19:49:06.000000000 -0700
@@ -45,7 +45,7 @@
  *
  */
 
-#include "portaudio.h"
+#include "../../portaudio-v19/include/portaudio.h"
 
 typedef void PxMixer;
 
diff -ur src/AudioIO.h src/AudioIO.h
--- src/AudioIO.h	2014-09-22 13:38:13.000000000 -0700
+++ src/AudioIO.h	2014-10-01 19:48:46.000000000 -0700
@@ -13,7 +13,7 @@
 #ifndef __AUDACITY_AUDIO_IO__
 #define __AUDACITY_AUDIO_IO__
 
-#include "portaudio.h"
+#include "../lib-src/portaudio-v19/include/portaudio.h"
 #include "Audacity.h"
 #include "Experimental.h"
 
diff -ur src/DeviceManager.cpp src/DeviceManager.cpp
--- src/DeviceManager.cpp	2014-09-22 13:38:13.000000000 -0700
+++ src/DeviceManager.cpp	2014-10-01 19:48:52.000000000 -0700
@@ -6,7 +6,7 @@
 
 ******************************************************************/
 
-#include "portaudio.h"
+#include "../lib-src/portaudio-v19/include/portaudio.h"
 #ifdef __WXMSW__
 #include "pa_win_wasapi.h"
 #endif
diff -ur src/prefs/DevicePrefs.cpp src/prefs/DevicePrefs.cpp
--- src/prefs/DevicePrefs.cpp	2014-09-22 13:38:13.000000000 -0700
+++ src/prefs/DevicePrefs.cpp	2014-10-01 19:48:39.000000000 -0700
@@ -30,7 +30,7 @@
 #include <wx/intl.h>
 #include <wx/log.h>
 
-#include "portaudio.h"
+#include "../../lib-src/portaudio-v19/include/portaudio.h"
 
 #include "../AudioIO.h"
 #include "../Internat.h"
