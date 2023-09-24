--- src/audio/audio.h.orig	2023-09-01 23:40:56 UTC
+++ src/audio/audio.h
@@ -31,3 +31,4 @@ extern AUDIO_RENDERER_CALLBACKS audio_callbacks_sdl;
 extern AUDIO_RENDERER_CALLBACKS audio_callbacks_pulse;
 bool audio_pulse_init(char* audio_device);
 #endif
+extern AUDIO_RENDERER_CALLBACKS audio_callbacks_oss;
