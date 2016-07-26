--- lib-src/portmixer/include/portmixer.h.orig	2016-07-26 13:34:07 UTC
+++ lib-src/portmixer/include/portmixer.h
@@ -45,7 +45,7 @@ extern "C"
  *
  */
 
-#include "portaudio.h"
+#include "../../portaudio-v19/include/portaudio.h"
 
 typedef void PxMixer;
 
