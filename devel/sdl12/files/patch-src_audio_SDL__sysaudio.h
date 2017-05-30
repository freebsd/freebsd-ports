$OpenBSD: patch-src_audio_SDL_sysaudio_h,v 1.6 2012/03/02 09:10:38 dcoppa Exp $
--- src/audio/SDL_sysaudio.h.orig	2012-01-19 06:30:06 UTC
+++ src/audio/SDL_sysaudio.h
@@ -105,6 +105,9 @@ typedef struct AudioBootStrap {
 #if SDL_AUDIO_DRIVER_BSD
 extern AudioBootStrap BSD_AUDIO_bootstrap;
 #endif
+#if SDL_AUDIO_DRIVER_SNDIO
+extern AudioBootStrap SNDIO_bootstrap;
+#endif
 #if SDL_AUDIO_DRIVER_PULSE
 extern AudioBootStrap PULSE_bootstrap;
 #endif
