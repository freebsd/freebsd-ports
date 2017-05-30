$OpenBSD: patch-src_audio_SDL_audio_c,v 1.17 2012/03/02 09:10:38 dcoppa Exp $
--- src/audio/SDL_audio.c.orig	2012-01-19 06:30:06 UTC
+++ src/audio/SDL_audio.c
@@ -36,11 +36,15 @@
 
 /* Available audio drivers */
 static AudioBootStrap *bootstrap[] = {
+
 #if SDL_AUDIO_DRIVER_PULSE
 	&PULSE_bootstrap,
 #endif
 #if SDL_AUDIO_DRIVER_ALSA
 	&ALSA_bootstrap,
+#endif
+#if SDL_AUDIO_DRIVER_SNDIO
+	&SNDIO_bootstrap,
 #endif
 #if SDL_AUDIO_DRIVER_BSD
 	&BSD_AUDIO_bootstrap,
