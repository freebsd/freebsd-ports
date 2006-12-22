--- snd_dma.c.orig	Fri Dec 22 02:00:07 2006
+++ snd_dma.c	Fri Dec 22 02:00:22 2006
@@ -90,11 +90,11 @@
 cvar_t s_swapstereo = {"s_swapstereo", "0", CVAR_ARCHIVE};
 
 cvar_t s_khz = {"s_khz", "11", CVAR_ARCHIVE};
-#ifdef __linux__
+#ifdef __unix__
 cvar_t s_noalsa = {"s_noalsa", "0"};
 // ALSA only -->
 cvar_t s_stereo = {"s_stereo", "1"};
-cvar_t s_device = {"s_device", "default"};
+cvar_t s_device = {"s_device", "/dev/dsp"};
 cvar_t s_bits = {"s_bits", "16"};
 // <-- ALSA only
 #endif
@@ -185,7 +185,7 @@
 	Cvar_Register(&s_show);
 	Cvar_Register(&s_mixahead);
 	Cvar_Register(&s_swapstereo);
-#ifdef __linux__
+#ifdef __unix__
 	Cvar_Register(&s_noalsa);
 	Cvar_Register(&s_stereo);
 	Cvar_Register(&s_device);
