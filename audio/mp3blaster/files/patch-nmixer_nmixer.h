--- nmixer/nmixer.h.orig	2018-01-28 10:54:10 UTC
+++ nmixer/nmixer.h
@@ -26,7 +26,7 @@
 
 #define MIXER_DEVICE "/dev/mixer"
 #define MYMIN(x, y) ((x) < (y) ? (x) : (y))
-#define MYVERSION "<<NMixer "VERSION">>"
+#define MYVERSION "<<NMixer " VERSION ">>"
 
 #define BOTH_CHANNELS 0x11
 #define RIGHT_CHANNEL 0x10
