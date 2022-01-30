--- oss/pcm_oss.c.orig	2020-02-19 09:35:42 UTC
+++ oss/pcm_oss.c
@@ -19,21 +19,42 @@
  */
 
 #include <stdio.h>
+#include <stdbool.h>
 #include <sys/ioctl.h>
 #include <alsa/asoundlib.h>
 #include <alsa/pcm_external.h>
+#ifdef __linux__
 #include <linux/soundcard.h>
+#else
+#include <sys/soundcard.h>
+#endif
 
+#ifndef ARRAY_SIZE
+#define	ARRAY_SIZE(x)	(sizeof(x) / sizeof(*(x)))
+#endif
+
+#define ALSA_OSS_RATE_MIN	1
+#define ALSA_OSS_RATE_MAX	384000
+
+#define ALSA_OSS_CHANNELS_MIN	1
+#define ALSA_OSS_CHANNELS_MAX	8
+
+#define ALSA_OSS_BUFSZ_MAX	131072
+#define ALSA_OSS_BLKCNT_MIN	2
+#define ALSA_OSS_BLKSZ_MIN	16 /* (ALSA_OSS_CHANNELS_MAX * 4) */
+
+#define ALSA_OSS_BUFSZ_MIN	(ALSA_OSS_BLKCNT_MIN * ALSA_OSS_BLKSZ_MIN)
+#define ALSA_OSS_BLKCNT_MAX	(ALSA_OSS_BUFSZ_MAX / ALSA_OSS_BUFSZ_MIN)
+#define ALSA_OSS_BLKSZ_MAX	(ALSA_OSS_BUFSZ_MAX / ALSA_OSS_BLKCNT_MIN)
+
 typedef struct snd_pcm_oss {
 	snd_pcm_ioplug_t io;
 	char *device;
 	int fd;
-	int fragment_set;
-	int caps;
+	int bufsz;
 	int format;
-	unsigned int period_shift;
-	unsigned int periods;
-	unsigned int frame_bytes;
+	int frame_bytes;
+	bool buffer_used;
 } snd_pcm_oss_t;
 
 static snd_pcm_sframes_t oss_write(snd_pcm_ioplug_t *io,
@@ -49,8 +70,21 @@ static snd_pcm_sframes_t oss_write(snd_pcm_ioplug_t *i
 	buf = (char *)areas->addr + (areas->first + areas->step * offset) / 8;
 	size *= oss->frame_bytes;
 	result = write(oss->fd, buf, size);
-	if (result <= 0)
-		return result;
+#ifdef __FreeBSD__
+	if (result == -1) {
+		if (errno == EAGAIN)
+			return 0;
+		else
+			return -errno;
+	}
+#else
+	if (result <= 0) {
+		if (result == -EAGAIN)
+			return 0;
+		else
+			return result;
+	}
+#endif
 	return result / oss->frame_bytes;
 }
 
@@ -67,24 +101,60 @@ static snd_pcm_sframes_t oss_read(snd_pcm_ioplug_t *io
 	buf = (char *)areas->addr + (areas->first + areas->step * offset) / 8;
 	size *= oss->frame_bytes;
 	result = read(oss->fd, buf, size);
-	if (result <= 0)
-		return result;
+#ifdef __FreeBSD__
+	if (result == -1) {
+		if (errno == EAGAIN)
+			return 0;
+		else
+			return -errno;
+	}
+#else
+	if (result <= 0) {
+		if (result == -EAGAIN)
+			return 0;
+		else
+			return result;
+	}
+#endif
 	return result / oss->frame_bytes;
 }
 
 static snd_pcm_sframes_t oss_pointer(snd_pcm_ioplug_t *io)
 {
 	snd_pcm_oss_t *oss = io->private_data;
-	struct count_info info;
-	int ptr;
+	audio_buf_info bi;
+	ssize_t bytes;
 
-	if (ioctl(oss->fd, io->stream == SND_PCM_STREAM_PLAYBACK ?
-		  SNDCTL_DSP_GETOPTR : SNDCTL_DSP_GETIPTR, &info) < 0) {
-		fprintf(stderr, "*** OSS: oss_pointer error\n");
-		return 0;
+	if (io->stream == SND_PCM_STREAM_PLAYBACK) {
+		if (ioctl(oss->fd, SNDCTL_DSP_GETOSPACE, &bi) < 0)
+			return -EINVAL;
+	} else {
+		if (ioctl(oss->fd, SNDCTL_DSP_GETISPACE, &bi) < 0)
+			return -EINVAL;
 	}
-	ptr = snd_pcm_bytes_to_frames(io->pcm, info.ptr);
-	return ptr;
+
+	/* check for over- and under- run */
+	if (bi.bytes != oss->bufsz) {
+		oss->buffer_used = true;
+	} else {
+		/* only report error once */
+		if (oss->buffer_used == true) {
+			oss->buffer_used = false;
+			return -EPIPE;
+		}
+	}
+
+	if (io->stream == SND_PCM_STREAM_PLAYBACK)
+		bi.bytes = oss->bufsz - bi.bytes;
+
+	/*
+	 * Return exactly how many bytes can be read or written,
+	 * relative to the current application pointer.
+	 */
+	bytes = snd_pcm_frames_to_bytes(io->pcm, io->appl_ptr) + bi.bytes;
+	bytes %= io->buffer_size * oss->frame_bytes;
+
+	return snd_pcm_bytes_to_frames(io->pcm, bytes);
 }
 
 static int oss_start(snd_pcm_ioplug_t *io)
@@ -93,12 +163,23 @@ static int oss_start(snd_pcm_ioplug_t *io)
 	int tmp = io->stream == SND_PCM_STREAM_PLAYBACK ?
 		PCM_ENABLE_OUTPUT : PCM_ENABLE_INPUT;
 
+#ifdef ALSA_OSS_DEBUG_VERBOSE
+	fprintf(stderr, "%s()\n", __func__);
+#endif
+
 	if (ioctl(oss->fd, SNDCTL_DSP_SETTRIGGER, &tmp) < 0) {
 		fprintf(stderr, "*** OSS: trigger failed\n");
+#ifdef __FreeBSD__
+		return -EINVAL;
+#else
 		if (io->stream == SND_PCM_STREAM_CAPTURE)
 			/* fake read to trigger */
 			read(oss->fd, &tmp, 0);
+#endif
 	}
+
+	oss->buffer_used = false;
+
 	return 0;
 }
 
@@ -107,6 +188,10 @@ static int oss_stop(snd_pcm_ioplug_t *io)
 	snd_pcm_oss_t *oss = io->private_data;
 	int tmp = 0;
 
+#ifdef ALSA_OSS_DEBUG_VERBOSE
+	fprintf(stderr, "%s()\n", __func__);
+#endif
+
 	ioctl(oss->fd, SNDCTL_DSP_SETTRIGGER, &tmp);
 	return 0;
 }
@@ -115,101 +200,176 @@ static int oss_drain(snd_pcm_ioplug_t *io)
 {
 	snd_pcm_oss_t *oss = io->private_data;
 
+#ifdef ALSA_OSS_DEBUG_VERBOSE
+	fprintf(stderr, "%s()\n", __func__);
+#endif
+
 	if (io->stream == SND_PCM_STREAM_PLAYBACK)
-		ioctl(oss->fd, SNDCTL_DSP_SYNC);
+		ioctl(oss->fd, SNDCTL_DSP_SYNC, NULL);
 	return 0;
 }
 
-static int oss_prepare(snd_pcm_ioplug_t *io)
+static int oss_delay(snd_pcm_ioplug_t *io, snd_pcm_sframes_t *delayp)
 {
 	snd_pcm_oss_t *oss = io->private_data;
 	int tmp;
 
-	ioctl(oss->fd, SNDCTL_DSP_RESET);
+	if (oss->fd < 0)
+		return -EBADFD;
 
-	tmp = io->channels;
-	if (ioctl(oss->fd, SNDCTL_DSP_CHANNELS, &tmp) < 0) {
-		perror("SNDCTL_DSP_CHANNELS");
-		return -EINVAL;
+	if (io->stream == SND_PCM_STREAM_PLAYBACK) {
+		if (ioctl(oss->fd, SNDCTL_DSP_GETODELAY, &tmp) < 0 || tmp < 0)
+			tmp = 0;
+	} else {
+		tmp = 0;
 	}
-	tmp = oss->format;
-	if (ioctl(oss->fd, SNDCTL_DSP_SETFMT, &tmp) < 0) {
-		perror("SNDCTL_DSP_SETFMT");
-		return -EINVAL;
-	}
-	tmp = io->rate;
-	if (ioctl(oss->fd, SNDCTL_DSP_SPEED, &tmp) < 0 ||
-	    tmp > io->rate * 1.01 || tmp < io->rate * 0.99) {
-		perror("SNDCTL_DSP_SPEED");
-		return -EINVAL;
-	}
-	return 0;
+	*delayp = snd_pcm_bytes_to_frames(io->pcm, tmp);
+
+	return (0);
 }
 
+static const struct {
+	int oss_format;
+	snd_pcm_format_t alsa_format;
+} oss_formats_tab[] = {
+	{ AFMT_U8, SND_PCM_FORMAT_U8 },
+	{ AFMT_S8, SND_PCM_FORMAT_S8 },
+	{ AFMT_MU_LAW, SND_PCM_FORMAT_MU_LAW  },
+	{  AFMT_A_LAW, SND_PCM_FORMAT_A_LAW   },
+	{ AFMT_S16_LE, SND_PCM_FORMAT_S16_LE  },
+	{ AFMT_S16_BE, SND_PCM_FORMAT_S16_BE  },
+	{ AFMT_U16_LE, SND_PCM_FORMAT_U16_LE  },
+	{ AFMT_U16_BE, SND_PCM_FORMAT_U16_BE  },
+	{ AFMT_S24_LE, SND_PCM_FORMAT_S24_3LE },
+	{ AFMT_S24_BE, SND_PCM_FORMAT_S24_3BE },
+	{ AFMT_U24_LE, SND_PCM_FORMAT_U24_3LE },
+	{ AFMT_U24_BE, SND_PCM_FORMAT_U24_3BE },
+	{ AFMT_S32_LE, SND_PCM_FORMAT_S32_LE  },
+	{ AFMT_S32_BE, SND_PCM_FORMAT_S32_BE  },
+	{ AFMT_U32_LE, SND_PCM_FORMAT_U32_LE  },
+	{ AFMT_U32_BE, SND_PCM_FORMAT_U32_BE  },
+	/* Special */
+	{ AFMT_S24_LE, SND_PCM_FORMAT_S20_3LE },
+	{ AFMT_S24_BE, SND_PCM_FORMAT_S20_3BE },
+	{ AFMT_U24_LE, SND_PCM_FORMAT_U20_3LE },
+	{ AFMT_U24_BE, SND_PCM_FORMAT_U20_3BE },
+	{ AFMT_S24_LE, SND_PCM_FORMAT_S18_3LE },
+	{ AFMT_S24_BE, SND_PCM_FORMAT_S18_3BE },
+	{ AFMT_U24_LE, SND_PCM_FORMAT_U18_3LE },
+	{ AFMT_U24_BE, SND_PCM_FORMAT_U18_3BE },
+	{ AFMT_S32_LE, SND_PCM_FORMAT_S24_LE  },
+	{ AFMT_S32_BE, SND_PCM_FORMAT_S24_BE  },
+	{ AFMT_U32_LE, SND_PCM_FORMAT_U24_LE  },
+	{ AFMT_U32_BE, SND_PCM_FORMAT_U24_BE  },
+};
+
 static int oss_hw_params(snd_pcm_ioplug_t *io,
 			 snd_pcm_hw_params_t *params ATTRIBUTE_UNUSED)
 {
 	snd_pcm_oss_t *oss = io->private_data;
 	int i, tmp, err;
-	unsigned int period_bytes;
+	int blksz_shift, blkcnt;
+	audio_buf_info bi;
 	long oflags, flags;
 
+#ifdef ALSA_OSS_DEBUG_VERBOSE
+	fprintf(stderr, "%s()\n", __func__);
+#endif
+
 	oss->frame_bytes = (snd_pcm_format_physical_width(io->format) * io->channels) / 8;
-	switch (io->format) {
-	case SND_PCM_FORMAT_U8:
-		oss->format = AFMT_U8;
-		break;
-	case SND_PCM_FORMAT_S16_LE:
-		oss->format = AFMT_S16_LE;
-		break;
-	case SND_PCM_FORMAT_S16_BE:
-		oss->format = AFMT_S16_BE;
-		break;
-	default:
+
+	oss->format = 0;
+	for (i = 0; i != ARRAY_SIZE(oss_formats_tab); i++) {
+		if (oss_formats_tab[i].alsa_format == io->format) {
+			oss->format = oss_formats_tab[i].oss_format;
+			break;
+		}
+	}
+	if (oss->format == 0) {
 		fprintf(stderr, "*** OSS: unsupported format %s\n", snd_pcm_format_name(io->format));
 		return -EINVAL;
 	}
-	period_bytes = io->period_size * oss->frame_bytes;
-	oss->period_shift = 0;
-	for (i = 31; i >= 4; i--) {
-		if (period_bytes & (1U << i)) {
-			oss->period_shift = i;
+
+	ioctl(oss->fd, SNDCTL_DSP_RESET);
+
+	/* use a 16ms HW buffer by default */
+	tmp = ((16 * io->rate) / 1000) * oss->frame_bytes;
+
+	/* round up to nearest power of two */
+	while (tmp & (tmp - 1))
+		tmp += tmp & ~(tmp - 1);
+
+	/* get logarithmic value */
+	for (blksz_shift = 0; blksz_shift < 24; blksz_shift++) {
+		if (tmp == (1 << blksz_shift))
 			break;
-		}
 	}
-	if (! oss->period_shift) {
-		fprintf(stderr, "*** OSS: invalid period size %d\n", (int)io->period_size);
-		return -EINVAL;
+
+	tmp = io->buffer_size * oss->frame_bytes;
+
+	/* compute HW buffer big enough to hold SW buffer */
+	for (blkcnt = ALSA_OSS_BLKCNT_MIN; blkcnt != ALSA_OSS_BLKCNT_MAX; blkcnt *= 2) {
+		if ((blkcnt << blksz_shift) >= tmp)
+			break;
 	}
-	oss->periods = io->buffer_size / io->period_size;
 
- _retry:
-	tmp = oss->period_shift | (oss->periods << 16);
+	tmp = blksz_shift | (blkcnt << 16);
 	if (ioctl(oss->fd, SNDCTL_DSP_SETFRAGMENT, &tmp) < 0) {
-		if (! oss->fragment_set) {
-			perror("SNDCTL_DSP_SETFRAGMENT");
-			fprintf(stderr, "*** period shift = %d, periods = %d\n", oss->period_shift, oss->periods);
-			return -EINVAL;
-		}
-		/* OSS has no proper way to reinitialize the fragments */
-		/* try to reopen the device */
-		close(oss->fd);
-		oss->fd = open(oss->device, io->stream == SND_PCM_STREAM_PLAYBACK ?
-			       O_WRONLY : O_RDONLY);
-		if (oss->fd < 0) {
-			err = -errno;
-			SNDERR("Cannot reopen the device %s", oss->device);
-			return err;
-		}
-		io->poll_fd = oss->fd;
-		io->poll_events = io->stream == SND_PCM_STREAM_PLAYBACK ?
-			POLLOUT : POLLIN;
-		snd_pcm_ioplug_reinit_status(io);
-		oss->fragment_set = 0;
-		goto _retry;
+		perror("SNDCTL_DSP_SETFRAGMENTS");
+		return -EINVAL;
 	}
-	oss->fragment_set = 1;
 
+	tmp = oss->format;
+	if (ioctl(oss->fd, SNDCTL_DSP_SETFMT, &tmp) < 0 ||
+	    tmp != oss->format) {
+		perror("SNDCTL_DSP_SETFMT");
+		return -EINVAL;
+	}
+
+	tmp = io->channels;
+	if (ioctl(oss->fd, SNDCTL_DSP_CHANNELS, &tmp) < 0 ||
+	    tmp != io->channels) {
+		perror("SNDCTL_DSP_CHANNELS");
+		return -EINVAL;
+	}
+
+	tmp = io->rate;
+	if (ioctl(oss->fd, SNDCTL_DSP_SPEED, &tmp) < 0 ||
+	    tmp > io->rate * 1.01 || tmp < io->rate * 0.99) {
+		perror("SNDCTL_DSP_SPEED");
+		return -EINVAL;
+	}
+
+	if (ioctl(oss->fd, (io->stream == SND_PCM_STREAM_PLAYBACK) ?
+	    SNDCTL_DSP_GETOSPACE : SNDCTL_DSP_GETISPACE, &bi) < 0) {
+		perror("SNDCTL_DSP_GET[I/O]SPACE");
+		return -EINVAL;
+	}
+
+	oss->bufsz = bi.fragsize * bi.fragstotal;
+
+#ifdef SNDCTL_DSP_LOW_WATER
+	tmp = io->period_size * oss->frame_bytes;
+	if (tmp > oss->bufsz)
+		tmp = oss->bufsz;
+	else if (tmp < bi.fragsize)
+		tmp = bi.fragsize;
+
+	if (ioctl(oss->fd, SNDCTL_DSP_LOW_WATER, &tmp) < 0)
+		perror("SNDCTL_DSP_LOW_WATER");
+#endif
+
+#ifdef ALSA_OSS_DEBUG_VERBOSE
+	fprintf(stderr,
+	    "\n\n[%lu -> %d] %lu ~ %d -> %d, %lu ~ %d -> %d [d:%ld lw:%d]\n\n",
+	    io->buffer_size / io->period_size, bi.fragstotal,
+	    io->buffer_size * oss->frame_bytes,
+	    (1 << blksz_shift) * blkcnt, oss->bufsz,
+	    io->period_size * oss->frame_bytes, 1 << blksz_shift,
+	    bi.fragsize,
+	    (long)(io->buffer_size * oss->frame_bytes) -
+	    oss->bufsz, tmp);
+#endif
 	if ((flags = fcntl(oss->fd, F_GETFL)) < 0) {
 		err = -errno;
 		perror("F_GETFL");
@@ -229,16 +389,148 @@ static int oss_hw_params(snd_pcm_ioplug_t *io,
 	return 0;
 }
 
-#define ARRAY_SIZE(ary)	(sizeof(ary)/sizeof(ary[0]))
-
 static int oss_hw_constraint(snd_pcm_oss_t *oss)
 {
+#ifdef __FreeBSD__
 	snd_pcm_ioplug_t *io = &oss->io; 
 	static const snd_pcm_access_t access_list[] = {
 		SND_PCM_ACCESS_RW_INTERLEAVED,
 		SND_PCM_ACCESS_MMAP_INTERLEAVED
 	};
+#ifdef FREEBSD_OSS_BLKCNT_P2
+	unsigned int period_list[30];
+#endif
+#ifdef FREEBSD_OSS_BUFSZ_P2
+	unsigned int bufsz_list[30];
+#endif
 	unsigned int nformats;
+	unsigned int format[ARRAY_SIZE(oss_formats_tab)];
+	int i, err, tmp;
+
+#ifdef ALSA_OSS_DEBUG_VERBOSE
+	fprintf(stderr, "%s()\n", __func__);
+#endif
+
+	/* check trigger */
+	tmp = 0;
+	if (ioctl(oss->fd, SNDCTL_DSP_GETCAPS, &tmp) >= 0) {
+		if (!(tmp & DSP_CAP_TRIGGER))
+			fprintf(stderr, "*** OSS: trigger is not supported!\n");
+	}
+
+	/* access type - interleaved only */
+	if ((err = snd_pcm_ioplug_set_param_list(io, SND_PCM_IOPLUG_HW_ACCESS,
+						 ARRAY_SIZE(access_list), access_list)) < 0)
+		return err;
+
+	/* supported formats. */
+	tmp = 0;
+	ioctl(oss->fd, SNDCTL_DSP_GETFMTS, &tmp);
+	nformats = 0;
+	for (i = 0; i < ARRAY_SIZE(oss_formats_tab); i++) {
+		if (tmp & oss_formats_tab[i].oss_format)
+			format[nformats++] = oss_formats_tab[i].alsa_format;
+	}
+	if (! nformats)
+		format[nformats++] = SND_PCM_FORMAT_S16;
+	if ((err = snd_pcm_ioplug_set_param_list(io, SND_PCM_IOPLUG_HW_FORMAT,
+						 nformats, format)) < 0)
+		return err;
+	
+#if 0
+	/* supported channels */
+	nchannels = 0;
+	for (i = 0; i < ARRAY_SIZE(channel); i++) {
+		tmp = i + 1;
+		if (ioctl(oss->fd, SNDCTL_DSP_CHANNELS, &tmp) >= 0 &&
+		    1 + i == tmp)
+			channel[nchannels++] = tmp;
+	}
+	if (! nchannels) /* assume 2ch stereo */
+		err = snd_pcm_ioplug_set_param_minmax(io,
+		    SND_PCM_IOPLUG_HW_CHANNELS, 2, 2);
+	else
+		err = snd_pcm_ioplug_set_param_list(io,
+		    SND_PCM_IOPLUG_HW_CHANNELS, nchannels, channel);
+	if (err < 0)
+		return err;
+#endif
+	err = snd_pcm_ioplug_set_param_minmax(io, SND_PCM_IOPLUG_HW_CHANNELS,
+	    ALSA_OSS_CHANNELS_MIN, ALSA_OSS_CHANNELS_MAX);
+	if (err < 0)
+		return err;
+
+	/* supported rates */
+	err = snd_pcm_ioplug_set_param_minmax(io, SND_PCM_IOPLUG_HW_RATE,
+	    ALSA_OSS_RATE_MIN, ALSA_OSS_RATE_MAX);
+	if (err < 0)
+		return err;
+
+	/*
+	 *  Maximum buffer size on FreeBSD can go up to 131072 bytes without
+	 *  strict ^2 alignment so that s24le in 3bytes packing can be fed
+	 *  directly.
+	 */
+
+#ifdef FREEBSD_OSS_BLKCNT_P2
+	tmp = 0;
+	for (i = 1; i < 31 && tmp < ARRAY_SIZE(period_list); i++) {
+		if ((1 << i) > ALSA_OSS_BLKCNT_MAX)
+			break;
+		if ((1 << i) < ALSA_OSS_BLKCNT_MIN)
+			continue;
+		period_list[tmp++] = 1 << i;
+	}
+
+	if (tmp > 0)
+		err = snd_pcm_ioplug_set_param_list(io,
+		    SND_PCM_IOPLUG_HW_PERIODS, tmp, period_list);
+	else
+#endif
+	/* periods , not strictly ^2 but later on will be refined */
+		err = snd_pcm_ioplug_set_param_minmax(io,
+		    SND_PCM_IOPLUG_HW_PERIODS, ALSA_OSS_BLKCNT_MIN,
+		    ALSA_OSS_BLKCNT_MAX);
+	if (err < 0)
+		return err;
+
+	/* period size , not strictly ^2 */
+	err = snd_pcm_ioplug_set_param_minmax(io,
+	    SND_PCM_IOPLUG_HW_PERIOD_BYTES, ALSA_OSS_BLKSZ_MIN,
+	    ALSA_OSS_BLKSZ_MAX);
+	if (err < 0)
+		return err;
+
+#ifdef FREEBSD_OSS_BUFSZ_P2
+	tmp = 0;
+	for (i = 1; i < 31 && tmp < ARRAY_SIZE(bufsz_list); i++) {
+		if ((1 << i) > ALSA_OSS_BUFSZ_MAX)
+			break;
+		if ((1 << i) < ALSA_OSS_BUFSZ_MIN)
+			continue;
+		bufsz_list[tmp++] = 1 << i;
+	}
+
+	if (tmp > 0)
+		err = snd_pcm_ioplug_set_param_list(io,
+		    SND_PCM_IOPLUG_HW_BUFFER_BYTES, tmp, bufsz_list);
+	else
+#endif
+	/* buffer size , not strictly ^2 */
+	err = snd_pcm_ioplug_set_param_minmax(io,
+	    SND_PCM_IOPLUG_HW_BUFFER_BYTES, ALSA_OSS_BUFSZ_MIN,
+	    ALSA_OSS_BUFSZ_MAX);
+	if (err < 0)
+		return err;
+
+	return 0;
+#else
+	snd_pcm_ioplug_t *io = &oss->io; 
+	static const snd_pcm_access_t access_list[] = {
+		SND_PCM_ACCESS_RW_INTERLEAVED,
+		SND_PCM_ACCESS_MMAP_INTERLEAVED
+	};
+	unsigned int nformats;
 	unsigned int format[5];
 	unsigned int nchannels;
 	unsigned int channel[6];
@@ -317,6 +609,7 @@ static int oss_hw_constraint(snd_pcm_oss_t *oss)
 		return err;
 
 	return 0;
+#endif
 }
 
 
@@ -324,6 +617,10 @@ static int oss_close(snd_pcm_ioplug_t *io)
 {
 	snd_pcm_oss_t *oss = io->private_data;
 
+#ifdef ALSA_OSS_DEBUG_VERBOSE
+	fprintf(stderr, "%s()\n", __func__);
+#endif
+
 	close(oss->fd);
 	free(oss->device);
 	free(oss);
@@ -337,8 +634,8 @@ static const snd_pcm_ioplug_callback_t oss_playback_ca
 	.pointer = oss_pointer,
 	.close = oss_close,
 	.hw_params = oss_hw_params,
-	.prepare = oss_prepare,
 	.drain = oss_drain,
+	.delay = oss_delay,
 };
 
 static const snd_pcm_ioplug_callback_t oss_capture_callback = {
@@ -348,8 +645,8 @@ static const snd_pcm_ioplug_callback_t oss_capture_cal
 	.pointer = oss_pointer,
 	.close = oss_close,
 	.hw_params = oss_hw_params,
-	.prepare = oss_prepare,
 	.drain = oss_drain,
+	.delay = oss_delay,
 };
 
 
@@ -360,6 +657,10 @@ SND_PCM_PLUGIN_DEFINE_FUNC(oss)
 	int err;
 	snd_pcm_oss_t *oss;
 	
+#ifdef ALSA_OSS_DEBUG_VERBOSE
+	fprintf(stderr, "%s()\n", __func__);
+#endif
+
 	snd_config_for_each(i, next, conf) {
 		snd_config_t *n = snd_config_iterator_entry(i);
 		const char *id;
