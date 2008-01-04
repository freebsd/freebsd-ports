--- snd_dma.c.orig	Fri Jan  4 07:05:02 2008
+++ snd_dma.c	Fri Jan  4 07:06:53 2008
@@ -94,7 +94,7 @@
 cvar_t s_khz = {"s_khz", "11", CVAR_ARCHIVE, OnChange_s_khz};
 #ifdef __FreeBSD__
 cvar_t s_stereo = {"s_stereo", "1"};
-cvar_t s_device = {"s_device", "/dev/dsp0.0"};
+cvar_t s_device = {"s_device", "/dev/dsp"};
 cvar_t s_bits = {"s_bits", "16"};
 #endif
 
