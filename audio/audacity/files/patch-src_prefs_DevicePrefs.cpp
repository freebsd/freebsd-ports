--- src/prefs/DevicePrefs.cpp.orig	2015-07-11 10:02:22 UTC
+++ src/prefs/DevicePrefs.cpp
@@ -30,7 +30,7 @@ other settings.
 #include <wx/intl.h>
 #include <wx/log.h>
 
-#include "portaudio.h"
+#include "../../lib-src/portaudio-v19/include/portaudio.h"
 
 #include "../AudioIO.h"
 #include "../Internat.h"
