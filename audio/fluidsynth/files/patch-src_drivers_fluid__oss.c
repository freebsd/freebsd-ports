--- src/drivers/fluid_oss.c.orig	2012-08-16 04:01:13 UTC
+++ src/drivers/fluid_oss.c
@@ -45,9 +45,9 @@
 #define BUFFER_LENGTH 512
 
 // Build issue on some systems (OSS 4.0)?
-#ifdef SNDCTL_DSP_CHANNELS
-  #define SOUND_PCM_WRITE_CHANNELS        SNDCTL_DSP_CHANNELS
-#endif
+// #ifdef SNDCTL_DSP_CHANNELS
+//   #define SOUND_PCM_WRITE_CHANNELS        SNDCTL_DSP_CHANNELS
+// #endif
 
 /** fluid_oss_audio_driver_t
  *
