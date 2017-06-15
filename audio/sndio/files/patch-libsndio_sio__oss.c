--- libsndio/sio_oss.c.orig	2016-11-06 11:21:59 UTC
+++ libsndio/sio_oss.c
@@ -108,6 +108,8 @@ static int sio_oss_xrun(struct sio_oss_hdl *);
 static size_t sio_oss_read(struct sio_hdl *, void *, size_t);
 static size_t sio_oss_write(struct sio_hdl *, const void *, size_t);
 static void sio_oss_close(struct sio_hdl *);
+static int sio_oss_setvol(struct sio_hdl *, unsigned int);
+static void sio_oss_getvol(struct sio_hdl *);
 
 static struct sio_ops sio_oss_ops = {
 	sio_oss_close,
@@ -121,8 +123,8 @@ static struct sio_ops sio_oss_ops = {
 	sio_oss_nfds,
 	sio_oss_pollfd,
 	sio_oss_revents,
-	NULL, /* setvol */
-	NULL, /* getvol */
+	sio_oss_setvol,
+	sio_oss_getvol,
 };
 
 /*
@@ -228,12 +230,10 @@ sio_oss_getcap(struct sio_hdl *sh, struct sio_cap *cap
 }
 
 static int
-sio_oss_getfd(const char *str, unsigned int mode, int nbio)
+_sio_oss_getdev(const char *str, char *path, size_t len)
 {
 	const char *p;
-	char path[DEVPATH_MAX];
 	unsigned int devnum;
-	int fd, flags, val;
 
 	p = _sndio_parsetype(str, "rsnd");
 	if (p == NULL) {
@@ -253,7 +253,24 @@ sio_oss_getfd(const char *str, unsigned int mode, int 
 		DPRINTF("sio_oss_getfd: %s: number expected after '/'\n", str);
 		return -1;
 	}
-	snprintf(path, sizeof(path), DEVPATH_PREFIX "%u", devnum);
+	snprintf(path, len, DEVPATH_PREFIX "%u", devnum);
+	return 0;
+}
+
+static int
+sio_oss_getfd(const char *str, unsigned int mode, int nbio)
+{
+	char path[DEVPATH_MAX];
+	int fd, flags, val;
+	audio_buf_info bi;
+
+	if (strcmp(str, SIO_DEVANY) == 0) {
+		/* Use /dev/dsp (the default device) directly */
+		snprintf(path, sizeof(path), DEVPATH_PREFIX);
+	} else if (_sio_oss_getdev(str, path, sizeof(path)) < 0) {
+		return -1;
+	}
+
 	if (mode == (SIO_PLAY | SIO_REC))
 		flags = O_RDWR;
 	else
@@ -264,6 +281,19 @@ sio_oss_getfd(const char *str, unsigned int mode, int 
 		DPERROR(path);
 		return -1;
 	}
+	/*
+	 * Check if the device supports playing/recording.
+	 * Unfortunately, it's possible for devices to be opened RDWR
+	 * even when they don't support playing/recording.
+	 */
+	if (mode & SIO_PLAY && ioctl(fd, SNDCTL_DSP_GETOSPACE, &bi) < 0) {
+		close(fd);
+		return -1;
+	}
+	if (mode & SIO_REC && ioctl(fd, SNDCTL_DSP_GETISPACE, &bi) < 0) {
+		close(fd);
+		return -1;
+	}
 	val = 1;
 	if (ioctl(fd, SNDCTL_DSP_LOW_WATER, &val) < 0) {
 		DPERROR("sio_oss_start: LOW_WATER");
@@ -383,13 +413,25 @@ sio_oss_setpar(struct sio_hdl *sh, struct sio_par *par
 	struct sio_oss_hdl *hdl = (struct sio_oss_hdl *)sh;
 	unsigned int i, round, bufsz;
 	int frag_max, frag_shift, frag_count, frag;
+	unsigned int le, sig, msb;
 
+	le = par->le;
+	sig = par->sig;
+	msb = par->msb;
+
+	if (le == ~0U)
+		le = 0;
+	if (sig == ~0U)
+		sig = 0;
+	if (msb == ~0U)
+		msb = 0;
+
 	hdl->fmt = AFMT_S16_LE;
 	for (i = 0; i < sizeof(formats)/sizeof(formats[0]); i++) {
 		if (formats[i].bits == par->bits &&
-		    formats[i].le == par->le &&
-		    formats[i].sig == par->sig &&
-		    formats[i].msb == par->msb) {
+		    formats[i].le == le &&
+		    formats[i].sig == sig &&
+		    formats[i].msb == msb) {
 			hdl->fmt = formats[i].fmt;
 			break;
 		}
@@ -734,6 +776,42 @@ sio_oss_revents(struct sio_hdl *sh, struct pollfd *pfd
 		hdl->odelta -= delta;
 	}
 	return revents;
+}
+
+static int
+sio_oss_setvol(struct sio_hdl *sh, unsigned int vol)
+{
+	struct sio_oss_hdl *hdl = (struct sio_oss_hdl *)sh;
+	int newvol;
+
+	/* Scale to 0..100 */
+	newvol = 1.0 * 100 * vol / SIO_MAXVOL;
+	newvol = newvol | (newvol << 8);
+
+	if (ioctl(hdl->fd, SNDCTL_DSP_SETPLAYVOL, &newvol) < 0) {
+		DPERROR("sio_oss_setvol");
+		hdl->sio.eof = 1;
+		return 0;
+	}
+
+	return 1;
+}
+
+static void
+sio_oss_getvol(struct sio_hdl *sh)
+{
+	struct sio_oss_hdl *hdl = (struct sio_oss_hdl *)sh;
+	int vol;
+
+	if (ioctl(hdl->fd, SNDCTL_DSP_GETPLAYVOL, &vol) < 0) {
+		DPERROR("sio_oss_getvol");
+		hdl->sio.eof = 1;
+		return;
+	}
+
+	/* Use left channel volume and scale to SIO_MAXVOL */
+	vol = SIO_MAXVOL * 1.0 * (vol & 0x7f) / 100;
+	_sio_onvol_cb(&hdl->sio, vol);
 }
 
 #endif /* defined USE_OSS */
