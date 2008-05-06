--- snd_dma.c.orig	2008-04-27 17:51:58.000000000 -0300
+++ snd_dma.c	2008-05-06 15:10:34.000000000 -0300
@@ -93,7 +93,7 @@
 cvar_t s_khz = {"s_khz", "11", CVAR_ARCHIVE, OnChange_s_khz};
 #ifdef __FreeBSD__
 cvar_t s_stereo = {"s_stereo", "1"};
-cvar_t s_device = {"s_device", "/dev/dsp0.0"};
+cvar_t s_device = {"s_device", "/dev/dsp"};
 cvar_t s_bits = {"s_bits", "16"};
 #endif
 
