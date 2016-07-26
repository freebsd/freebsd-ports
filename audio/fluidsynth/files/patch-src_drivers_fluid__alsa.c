--- src/drivers/fluid_alsa.c.orig	2012-08-16 04:01:13 UTC
+++ src/drivers/fluid_alsa.c
@@ -347,14 +347,16 @@ static int fluid_alsa_handle_write_error
   case -EAGAIN:
     snd_pcm_wait(pcm, 1);
     break;
-  case -EPIPE:
   case -EBADFD:
     if (snd_pcm_prepare(pcm) != 0) {
       FLUID_LOG(FLUID_ERR, "Failed to prepare the audio device");
       return FLUID_FAILED;
     }
     break;
+  case -EPIPE:
+#if EPIPE != ESTRPIPE
   case -ESTRPIPE:
+#endif
     if ((snd_pcm_resume(pcm) != 0) && (snd_pcm_prepare(pcm) != 0)) {
       FLUID_LOG(FLUID_ERR, "Failed to resume the audio device");
       return FLUID_FAILED;
