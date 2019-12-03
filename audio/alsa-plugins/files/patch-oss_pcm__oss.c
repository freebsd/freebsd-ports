--- oss/pcm_oss.c.orig	2016-03-31 13:11:29 UTC
+++ oss/pcm_oss.c
@@ -22,7 +22,11 @@
 #include <sys/ioctl.h>
 #include <alsa/asoundlib.h>
 #include <alsa/pcm_external.h>
+#ifdef __linux__
 #include <linux/soundcard.h>
+#else
+#include <sys/soundcard.h>
+#endif
 
 typedef struct snd_pcm_oss {
 	snd_pcm_ioplug_t io;
@@ -116,7 +120,7 @@ static int oss_drain(snd_pcm_ioplug_t *io)
 	snd_pcm_oss_t *oss = io->private_data;
 
 	if (io->stream == SND_PCM_STREAM_PLAYBACK)
-		ioctl(oss->fd, SNDCTL_DSP_SYNC);
+		ioctl(oss->fd, SNDCTL_DSP_SYNC, NULL);
 	return 0;
 }
 
@@ -125,7 +129,7 @@ static int oss_prepare(snd_pcm_ioplug_t *io)
 	snd_pcm_oss_t *oss = io->private_data;
 	int tmp;
 
-	ioctl(oss->fd, SNDCTL_DSP_RESET);
+	ioctl(oss->fd, SNDCTL_DSP_RESET, NULL);
 
 	tmp = io->channels;
 	if (ioctl(oss->fd, SNDCTL_DSP_CHANNELS, &tmp) < 0) {
