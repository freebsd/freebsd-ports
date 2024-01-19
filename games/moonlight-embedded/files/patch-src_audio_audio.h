--- src/audio/audio.h.orig	2023-11-03 06:08:34 UTC
+++ src/audio/audio.h
@@ -31,3 +31,6 @@ extern AUDIO_RENDERER_CALLBACKS audio_callbacks_sdl;
 extern AUDIO_RENDERER_CALLBACKS audio_callbacks_pulse;
 bool audio_pulse_init(char* audio_device);
 #endif
+#ifdef __FreeBSD__
+extern AUDIO_RENDERER_CALLBACKS audio_callbacks_oss;
+#endif
