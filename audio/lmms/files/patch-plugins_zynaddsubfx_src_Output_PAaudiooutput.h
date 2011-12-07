--- plugins/zynaddsubfx/src/Output/PAaudiooutput.h.orig	2011-10-04 21:29:52.000000000 +0000
+++ plugins/zynaddsubfx/src/Output/PAaudiooutput.h	2011-10-04 21:30:34.000000000 +0000
@@ -22,7 +22,7 @@
 #ifndef PA_AUDIO_OUTPUT_H
 #define PA_AUDIO_OUTPUT_H
 
-#include <portaudio.h>
+#include <portaudio2/portaudio.h>
 
 #include "../globals.h"
 #include "../Misc/Master.h"
