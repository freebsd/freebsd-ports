--- snd_dma.c.orig	Thu Oct 19 16:52:41 2006
+++ snd_dma.c	Tue Dec 19 20:53:19 2006
@@ -90,7 +90,7 @@
 cvar_t s_swapstereo = {"s_swapstereo", "0", CVAR_ARCHIVE};
 
 cvar_t s_khz = {"s_khz", "11", CVAR_ARCHIVE};
-#ifdef __linux__
+#ifdef __unix__
 cvar_t s_noalsa = {"s_noalsa", "0"};
 // ALSA only -->
 cvar_t s_stereo = {"s_stereo", "1"};
@@ -185,7 +185,7 @@
 	Cvar_Register(&s_show);
 	Cvar_Register(&s_mixahead);
 	Cvar_Register(&s_swapstereo);
-#ifdef __linux__
+#ifdef __unix__
 	Cvar_Register(&s_noalsa);
 	Cvar_Register(&s_stereo);
 	Cvar_Register(&s_device);
