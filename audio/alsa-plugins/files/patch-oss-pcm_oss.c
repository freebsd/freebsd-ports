--- oss/pcm_oss.c.orig	2008-10-29 08:42:13.000000000 -0400
+++ oss/pcm_oss.c
@@ -22,4 +22,8 @@
 #include <sys/ioctl.h>
 #include <alsa/asoundlib.h>
 #include <alsa/pcm_external.h>
+#ifdef __linux__
 #include <linux/soundcard.h>
+#else
+#include <sys/soundcard.h>
+#endif
@@ -116,7 +120,7 @@ static int oss_drain(snd_pcm_ioplug_t *i
 	snd_pcm_oss_t *oss = io->private_data;
 
 	if (io->stream == SND_PCM_STREAM_PLAYBACK)
-		ioctl(oss->fd, SNDCTL_DSP_SYNC);
+		ioctl(oss->fd, SNDCTL_DSP_SYNC, NULL);
 	return 0;
 }
 
@@ -125,7 +129,7 @@ static int oss_prepare(snd_pcm_ioplug_t 
 	snd_pcm_oss_t *oss = io->private_data;
 	int tmp;
 
-	ioctl(oss->fd, SNDCTL_DSP_RESET);
+	ioctl(oss->fd, SNDCTL_DSP_RESET, NULL);
 
 	tmp = io->channels;
 	if (ioctl(oss->fd, SNDCTL_DSP_CHANNELS, &tmp) < 0) {
