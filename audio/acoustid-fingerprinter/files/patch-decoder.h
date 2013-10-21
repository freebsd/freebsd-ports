--- decoder.h.orig	2013-10-21 12:47:16.077685162 -0200
+++ decoder.h	2013-10-21 12:47:47.588683149 -0200
@@ -35,6 +35,10 @@
 }
 #include "fingerprintcalculator.h"
 
+#ifndef AVCODEC_MAX_AUDIO_FRAME_SIZE
+#define AVCODEC_MAX_AUDIO_FRAME_SIZE 192000 // 1 second of 48khz 32bit audio
+#endif
+
 #if LIBAVCODEC_VERSION_INT < AV_VERSION_INT(52, 64, 0)
 #define AV_SAMPLE_FMT_S16 SAMPLE_FMT_S16
 #endif
