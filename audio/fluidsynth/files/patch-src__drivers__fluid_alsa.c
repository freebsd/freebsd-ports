--- src/drivers/fluid_alsa.c	2012-08-16 00:01:13.000000000 -0400
+++ src/drivers/fluid_alsa.c	2014-12-20 12:59:44.000000000 -0500
@@ -348,5 +348,4 @@
     snd_pcm_wait(pcm, 1);
     break;
-  case -EPIPE:
   case -EBADFD:
     if (snd_pcm_prepare(pcm) != 0) {
@@ -355,5 +354,8 @@
     }
     break;
+  case -EPIPE:
+#if EPIPE != ESTRPIPE
   case -ESTRPIPE:
+#endif
     if ((snd_pcm_resume(pcm) != 0) && (snd_pcm_prepare(pcm) != 0)) {
       FLUID_LOG(FLUID_ERR, "Failed to resume the audio device");
