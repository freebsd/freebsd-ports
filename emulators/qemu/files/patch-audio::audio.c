Index: qemu/audio/audio.c
@@ -28,6 +28,10 @@
 
 #include "audio/audio_int.h"
 
+#ifndef INT16_MAX
+#define	INT16_MAX	0x7fff
+#endif
+
 #define dolog(...) AUD_log ("audio", __VA_ARGS__)
 #ifdef DEBUG
 #define ldebug(...) dolog (__VA_ARGS__)
