--- include/AudioPortAudio.h.orig	2011-10-04 21:28:47.000000000 +0000
+++ include/AudioPortAudio.h	2011-10-04 21:29:25.000000000 +0000
@@ -45,7 +45,7 @@
 
 #ifdef LMMS_HAVE_PORTAUDIO
 
-#include <portaudio.h>
+#include <portaudio2/portaudio.h>
 
 #include "AudioDevice.h"
 
