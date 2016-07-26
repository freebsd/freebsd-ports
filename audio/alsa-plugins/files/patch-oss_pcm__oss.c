--- oss/pcm_oss.c.orig	2016-07-26 13:27:23 UTC
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
 
 #define ARRAY_SIZE(x)	(sizeof(x) / sizeof(*(x)))
 
@@ -258,7 +262,7 @@ static int oss_drain(snd_pcm_ioplug_t *i
 #endif
 
 	if (io->stream == SND_PCM_STREAM_PLAYBACK)
-		ioctl(oss->fd, SNDCTL_DSP_SYNC);
+		ioctl(oss->fd, SNDCTL_DSP_SYNC, NULL);
 	return 0;
 }
 
@@ -272,7 +276,7 @@ static int oss_prepare(snd_pcm_ioplug_t 
 	fprintf(stderr, "%s()\n", __func__);
 #endif
 
-	ioctl(oss->fd, SNDCTL_DSP_RESET);
+	ioctl(oss->fd, SNDCTL_DSP_RESET, NULL);
 
 	tmp = io->channels;
 	if (ioctl(oss->fd, SNDCTL_DSP_CHANNELS, &tmp) < 0) {
