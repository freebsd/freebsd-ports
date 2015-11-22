--- lib-src/portmixer/include/portmixer.h.orig	2015-07-11 10:02:22 UTC
+++ lib-src/portmixer/include/portmixer.h
@@ -45,7 +45,7 @@ extern "C"
  *
  */
 
-#include "portaudio.h"
+#include "../../portaudio-v19/include/portaudio.h"
 
 typedef void PxMixer;
 
