--- oss/pcm_oss.c.orig	2019-07-04 14:37:07 UTC
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
 
@@ -74,11 +78,19 @@ static snd_pcm_sframes_t oss_write(snd_p
 	size *= oss->frame_bytes;
 	result = write(oss->fd, buf, size);
 #ifdef __FreeBSD__
-	if (result == -1)
-		return -errno;
+	if (result == -1) {
+		if (errno == EAGAIN)
+			return 0;
+		else
+			return -errno;
+	}
 #else
-	if (result <= 0)
-		return result;
+	if (result <= 0) {
+		if (result == -EAGAIN)
+			return 0;
+		else
+			return result;
+	}
 #endif
 	return result / oss->frame_bytes;
 }
@@ -97,11 +109,19 @@ static snd_pcm_sframes_t oss_read(snd_pc
 	size *= oss->frame_bytes;
 	result = read(oss->fd, buf, size);
 #ifdef __FreeBSD__
-	if (result == -1)
-		return -errno;
+	if (result == -1) {
+		if (errno == EAGAIN)
+			return 0;
+		else
+			return -errno;
+	}
 #else
-	if (result <= 0)
-		return result;
+	if (result <= 0) {
+		if (result == -EAGAIN)
+			return 0;
+		else
+			return result;
+	}
 #endif
 	return result / oss->frame_bytes;
 }
@@ -258,10 +278,29 @@ static int oss_drain(snd_pcm_ioplug_t *i
 #endif
 
 	if (io->stream == SND_PCM_STREAM_PLAYBACK)
-		ioctl(oss->fd, SNDCTL_DSP_SYNC);
+		ioctl(oss->fd, SNDCTL_DSP_SYNC, NULL);
 	return 0;
 }
 
+static int oss_delay(snd_pcm_ioplug_t *io, snd_pcm_sframes_t *delayp)
+{
+	snd_pcm_oss_t *oss = io->private_data;
+	int tmp;
+
+	if (oss->fd < 0)
+		return -EBADFD;
+
+	if (io->stream == SND_PCM_STREAM_PLAYBACK) {
+		if (ioctl(oss->fd, SNDCTL_DSP_GETODELAY, &tmp) < 0 || tmp < 0)
+			tmp = 0;
+	} else {
+		tmp = 0;
+	}
+	*delayp = snd_pcm_bytes_to_frames(io->pcm, tmp);
+
+	return (0);
+}
+
 #ifndef __FreeBSD__
 static int oss_prepare(snd_pcm_ioplug_t *io)
 {
@@ -272,7 +311,7 @@ static int oss_prepare(snd_pcm_ioplug_t 
 	fprintf(stderr, "%s()\n", __func__);
 #endif
 
-	ioctl(oss->fd, SNDCTL_DSP_RESET);
+	ioctl(oss->fd, SNDCTL_DSP_RESET, NULL);
 
 	tmp = io->channels;
 	if (ioctl(oss->fd, SNDCTL_DSP_CHANNELS, &tmp) < 0) {
@@ -380,20 +419,26 @@ static int oss_hw_params(snd_pcm_ioplug_
 
 	ioctl(oss->fd, SNDCTL_DSP_RESET);
 
-#define blksz_aligned()		((1 << blksz_shift) -			\
-				((1 << blksz_shift) % oss->frame_bytes))
-	blksz_shift = 16;
-	tmp = io->period_size * oss->frame_bytes;
+	/* use a 16ms HW buffer by default */
+	tmp = ((16 * io->rate) / 1000) * oss->frame_bytes;
 
-	while (blksz_shift > 4 && blksz_aligned() > tmp)
-		blksz_shift--;
+	/* round up to nearest power of two */
+	while (tmp & (tmp - 1))
+		tmp += tmp & ~(tmp - 1);
+
+	/* get logarithmic value */
+	for (blksz_shift = 0; blksz_shift < 24; blksz_shift++) {
+		if (tmp == (1 << blksz_shift))
+			break;
+	}
 
-	blkcnt = 2;
 	tmp = io->buffer_size * oss->frame_bytes;
 
-	while (blkcnt < 4096 && (blksz_aligned() * blkcnt) < tmp &&
-	    ((1 << blksz_shift) * blkcnt) < 131072)
-		blkcnt <<= 1;
+	/* compute HW buffer big enough to hold SW buffer */
+	for (blkcnt = FREEBSD_OSS_BLKCNT_MIN; blkcnt != FREEBSD_OSS_BLKCNT_MAX; blkcnt *= 2) {
+		if ((blkcnt << blksz_shift) >= tmp)
+			break;
+	}
 
 	tmp = blksz_shift | (blkcnt << 16);
 	if (ioctl(oss->fd, SNDCTL_DSP_SETFRAGMENT, &tmp) < 0) {
@@ -767,6 +812,7 @@ static const snd_pcm_ioplug_callback_t o
 	.prepare = oss_prepare,
 #endif
 	.drain = oss_drain,
+	.delay = oss_delay,
 };
 
 static const snd_pcm_ioplug_callback_t oss_capture_callback = {
@@ -780,6 +826,7 @@ static const snd_pcm_ioplug_callback_t o
 	.prepare = oss_prepare,
 #endif
 	.drain = oss_drain,
+	.delay = oss_delay,
 };
 
 
