--- src/drivers/fluid_oss.c.orig	2018-05-06 07:05:11 UTC
+++ src/drivers/fluid_oss.c
@@ -45,9 +45,9 @@
 #define BUFFER_LENGTH 512
 
 // Build issue on some systems (OSS 4.0)?
-#if !defined(SOUND_PCM_WRITE_CHANNELS) && defined(SNDCTL_DSP_CHANNELS)
-  #define SOUND_PCM_WRITE_CHANNELS        SNDCTL_DSP_CHANNELS
-#endif
+// #if !defined(SOUND_PCM_WRITE_CHANNELS) && defined(SNDCTL_DSP_CHANNELS)
+//   #define SOUND_PCM_WRITE_CHANNELS        SNDCTL_DSP_CHANNELS
+// #endif
 
 /** fluid_oss_audio_driver_t
  *
