--- libsndio/sio_oss.c.orig	2016-08-20 02:30:22 UTC
+++ libsndio/sio_oss.c
@@ -0,0 +1,838 @@
+/*	$OpenBSD$	*/
+/*
+ * Copyright (c) 2008 Alexandre Ratchov <alex@caoua.org>
+ * Copyright (c) 2016 Tobias Kortkamp <t@tobik.me>
+ *
+ * Permission to use, copy, modify, and distribute this software for any
+ * purpose with or without fee is hereby granted, provided that the above
+ * copyright notice and this permission notice appear in all copies.
+ *
+ * THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES
+ * WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF
+ * MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR
+ * ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES
+ * WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN
+ * ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF
+ * OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
+ */
+
+#ifdef USE_OSS
+#include <sys/types.h>
+#include <sys/ioctl.h>
+#include <sys/param.h>
+#include <sys/soundcard.h>
+#include <sys/stat.h>
+
+#include <errno.h>
+#include <fcntl.h>
+#include <limits.h>
+#include <poll.h>
+#include <stdio.h>
+#include <stdlib.h>
+#include <string.h>
+#include <unistd.h>
+
+#include "debug.h"
+#include "sio_priv.h"
+#include "bsd-compat.h"
+
+#define DEVPATH_PREFIX	"/dev/dsp"
+#define DEVPATH_MAX 	(1 +		\
+	sizeof(DEVPATH_PREFIX) - 1 +	\
+	sizeof(int) * 3)
+
+#define AUDIO_INITPAR(p)						\
+	(void)memset((void *)(p), 0xff, sizeof(struct audio_swpar))
+
+/*
+ * argument to AUDIO_SETPAR and AUDIO_GETPAR ioctls
+ */
+struct audio_swpar {
+	unsigned int sig;		/* if 1, encoding is signed */
+	unsigned int le;		/* if 1, encoding is little-endian */
+	unsigned int bits;		/* bits per sample */
+	unsigned int bps;		/* bytes per sample */
+	unsigned int msb;		/* if 1, bits are msb-aligned */
+	unsigned int rate;		/* common play & rec sample rate */
+	unsigned int pchan;		/* play channels */
+	unsigned int rchan;		/* rec channels */
+	unsigned int nblks;		/* number of blocks in play buffer */
+	unsigned int round;		/* common frames per block */
+	unsigned int _spare[6];
+};
+
+struct sio_oss_hdl {
+	struct sio_hdl sio;
+	int fd;
+	unsigned int ibpf, obpf;	/* bytes per frame */
+	unsigned int isamples;
+	unsigned int osamples;
+	int idelta, odelta;		/* position reported to client */
+
+	char *devstr;
+
+	/* OSS doesn't have an API to ask for device parameters
+	 * without setting them, so we keep track of them ourselves.
+	 */
+	struct audio_swpar swpar;
+};
+
+static void sio_oss_close(struct sio_hdl *);
+static int sio_oss_start(struct sio_hdl *);
+static int sio_oss_stop(struct sio_hdl *);
+static int sio_oss_setpar(struct sio_hdl *, struct sio_par *);
+static int sio_oss_getpar(struct sio_hdl *, struct sio_par *);
+static int sio_oss_getcap(struct sio_hdl *, struct sio_cap *);
+static size_t sio_oss_read(struct sio_hdl *, void *, size_t);
+static size_t sio_oss_write(struct sio_hdl *, const void *, size_t);
+static int sio_oss_nfds(struct sio_hdl *);
+static int sio_oss_pollfd(struct sio_hdl *, struct pollfd *, int);
+static int sio_oss_revents(struct sio_hdl *, struct pollfd *);
+
+static void sio_oss_fmt_to_swpar(int, struct audio_swpar *);
+static int sio_oss_audio_getpar(struct sio_oss_hdl *, struct audio_swpar *);
+static int sio_oss_audio_setpar(struct sio_oss_hdl *, struct audio_swpar *);
+static int sio_oss_reopen(struct sio_oss_hdl *);
+
+static struct sio_ops sio_oss_ops = {
+	sio_oss_close,
+	sio_oss_setpar,
+	sio_oss_getpar,
+	sio_oss_getcap,
+	sio_oss_write,
+	sio_oss_read,
+	sio_oss_start,
+	sio_oss_stop,
+	sio_oss_nfds,
+	sio_oss_pollfd,
+	sio_oss_revents,
+	NULL, /* setvol */
+	NULL, /* getvol */
+};
+
+static int
+sio_oss_adjpar(struct sio_oss_hdl *hdl, struct audio_swpar *ap)
+{
+	if (hdl->sio.eof)
+		return 0;
+	if (sio_oss_audio_setpar(hdl, ap)) {
+		DPERROR("AUDIO_SETPAR");
+		hdl->sio.eof = 1;
+		return 0;
+	}
+	if (sio_oss_audio_getpar(hdl, ap)) {
+		DPERROR("AUDIO_GETPAR");
+		hdl->sio.eof = 1;
+		return 0;
+	}
+	return 1;
+}
+
+/*
+ * try to set the device to the given parameters and check that the
+ * device can use them; return 1 on success, 0 on failure or error
+ */
+static int
+sio_oss_testpar(struct sio_oss_hdl *hdl, struct sio_enc *enc,
+    unsigned int pchan, unsigned int rchan, unsigned int rate)
+{
+	struct audio_swpar ap;
+
+	AUDIO_INITPAR(&ap);
+	if (enc != NULL) {
+		ap.sig = enc->sig;
+		ap.bits = enc->bits;
+		ap.bps = enc->bps;
+		if (ap.bps > 1)
+			ap.le = enc->le;
+		if (ap.bps * 8 > ap.bits)
+			ap.msb = enc->msb;
+	}
+	if (rate)
+		ap.rate = rate;
+	if (pchan && (hdl->sio.mode & SIO_PLAY))
+		ap.pchan = pchan;
+	if (rchan && (hdl->sio.mode & SIO_REC))
+		ap.rchan = rchan;
+	if (!sio_oss_adjpar(hdl, &ap))
+		return 0;
+	if (pchan && ap.pchan != pchan)
+		return 0;
+	if (rchan && ap.rchan != rchan)
+		return 0;
+	if (rate && ap.rate != rate)
+		return 0;
+	if (enc) {
+		if (ap.sig != enc->sig)
+			return 0;
+		if (ap.bits != enc->bits)
+			return 0;
+		if (ap.bps != enc->bps)
+			return 0;
+		if (ap.bps > 1 && ap.le != enc->le)
+			return 0;
+		if (ap.bits < ap.bps * 8 && ap.msb != enc->msb)
+			return 0;
+	}
+	return 1;
+}
+
+/*
+ * guess device capabilities
+ */
+static int
+sio_oss_getcap(struct sio_hdl *sh, struct sio_cap *cap)
+{
+	static unsigned int chans[] = {
+		1, 2, 4, 6, 8, 10, 12
+	};
+	static unsigned int rates[] = {
+		8000, 11025, 12000, 16000, 22050, 24000,
+		32000, 44100, 48000, 64000, 88200, 96000
+	};
+	static unsigned int encs[] = {
+		8, 16, 24, 32
+	};
+	struct sio_oss_hdl *hdl = (struct sio_oss_hdl *)sh;
+	struct audio_swpar savepar, ap;
+	unsigned int nconf = 0;
+	unsigned int enc_map = 0, rchan_map = 0, pchan_map = 0, rate_map;
+	unsigned int i, j, conf;
+
+	if (sio_oss_audio_getpar(hdl, &savepar)) {
+		DPERROR("AUDIO_GETPAR");
+		hdl->sio.eof = 1;
+		return 0;
+	}
+
+	/*
+	 * get a subset of supported encodings
+	 */
+	for (i = 0; i < sizeof(encs) / sizeof(encs[0]); i++) {
+		AUDIO_INITPAR(&ap);
+		ap.bits = encs[i];
+		ap.sig = (ap.bits > 8) ? 1 : 0;
+		if (!sio_oss_adjpar(hdl, &ap))
+			return 0;
+		if (ap.bits == encs[i]) {
+			cap->enc[i].sig = ap.sig;
+			cap->enc[i].bits = ap.bits;
+			cap->enc[i].le = ap.le;
+			cap->enc[i].bps = ap.bps;
+			cap->enc[i].msb = ap.msb;
+			enc_map |= 1 << i;
+		}
+	}
+
+	/*
+	 * fill channels
+	 *
+	 * for now we're lucky: all kernel devices assume that the
+	 * number of channels and the encoding are independent so we can
+	 * use the current encoding and try various channels.
+	 */
+	if (hdl->sio.mode & SIO_PLAY) {
+		for (i = 0; i < sizeof(chans) / sizeof(chans[0]); i++) {
+			AUDIO_INITPAR(&ap);
+			ap.pchan = chans[i];
+			if (!sio_oss_adjpar(hdl, &ap))
+				return 0;
+			if (ap.pchan == chans[i]) {
+				cap->pchan[i] = chans[i];
+				pchan_map |= (1 << i);
+			}
+		}
+	}
+	if (hdl->sio.mode & SIO_REC) {
+		for (i = 0; i < sizeof(chans) / sizeof(chans[0]); i++) {
+			AUDIO_INITPAR(&ap);
+			ap.pchan = chans[i];
+			if (!sio_oss_adjpar(hdl, &ap))
+				return 0;
+			if (ap.rchan == chans[i]) {
+				cap->rchan[i] = chans[i];
+				rchan_map |= (1 << i);
+			}
+		}
+	}
+
+	/*
+	 * fill rates
+	 *
+	 * rates are not independent from other parameters (eg. on
+	 * uaudio devices), so certain rates may not be allowed with
+	 * certain encodings. We have to check rates for all encodings
+	 */
+	for (j = 0; j < sizeof(encs) / sizeof(encs[0]); j++) {
+		rate_map = 0;
+		if ((enc_map & (1 << j)) == 0)
+			continue;
+		for (i = 0; i < sizeof(rates) / sizeof(rates[0]); i++) {
+			if (sio_oss_testpar(hdl,
+				&cap->enc[j], 0, 0, rates[i])) {
+				cap->rate[i] = rates[i];
+				rate_map |= (1 << i);
+			}
+		}
+		for (conf = 0; conf < nconf; conf++) {
+			if (cap->confs[conf].rate == rate_map) {
+				cap->confs[conf].enc |= (1 << j);
+				break;
+			}
+		}
+		if (conf == nconf) {
+			if (nconf == SIO_NCONF)
+				break;
+			cap->confs[nconf].enc = (1 << j);
+			cap->confs[nconf].pchan = pchan_map;
+			cap->confs[nconf].rchan = rchan_map;
+			cap->confs[nconf].rate = rate_map;
+			nconf++;
+		}
+	}
+	cap->nconf = nconf;
+
+	if (sio_oss_audio_setpar(hdl, &savepar)) {
+		DPERROR("AUDIO_SETPAR");
+		hdl->sio.eof = 1;
+		return 0;
+	}
+	return 1;
+}
+
+static int
+sio_oss_getfd(const char *str, unsigned int mode, int nbio)
+{
+	const char *p;
+	char path[DEVPATH_MAX];
+	unsigned int devnum;
+	int fd, flags;
+
+	if (strcmp(str, "fallback") == 0) {
+		/* On FreeBSD /dev/dsp points to the default unit
+		 * selectable with the hw.snd.default_unit sysctl.
+		 * Use it as fallback device.
+		 */
+		snprintf(path, sizeof(path), DEVPATH_PREFIX);
+	} else {
+		p = _sndio_parsetype(str, "rsnd");
+		if (p == NULL) {
+			DPRINTF("sio_oss_getfd: %s: \"rsnd\" expected\n", str);
+			return -1;
+		}
+		switch (*p) {
+		case '/':
+			p++;
+			break;
+		default:
+			DPRINTF("sio_oss_getfd: %s: '/' expected\n", str);
+			return -1;
+		}
+		p = _sndio_parsenum(p, &devnum, 255);
+		if (p == NULL || *p != '\0') {
+			DPRINTF("sio_oss_getfd: %s: number expected after '/'\n", str);
+			return -1;
+		}
+		snprintf(path, sizeof(path), DEVPATH_PREFIX "%u", devnum);
+	}
+	if (mode == (SIO_PLAY | SIO_REC))
+		flags = O_RDWR;
+	else
+		flags = (mode & SIO_PLAY) ? O_WRONLY : O_RDONLY;
+	while ((fd = open(path, flags | O_NONBLOCK | O_CLOEXEC)) < 0) {
+		if (errno == EINTR)
+			continue;
+		DPERROR(path);
+		return -1;
+	}
+	return fd;
+}
+
+static struct sio_oss_hdl *
+sio_oss_fdopen(int fd, unsigned int mode, int nbio)
+{
+	struct sio_oss_hdl *hdl;
+
+	hdl = malloc(sizeof(struct sio_oss_hdl));
+	if (hdl == NULL)
+		return NULL;
+	_sio_create(&hdl->sio, &sio_oss_ops, mode, nbio);
+
+	/* Set default device parameters */
+	sio_oss_fmt_to_swpar(AFMT_S16_LE, &hdl->swpar);
+	hdl->swpar.msb = 1;
+	hdl->swpar.rate = 48000;
+	hdl->swpar.bps = SIO_BPS(hdl->swpar.bits);
+	hdl->swpar.pchan = hdl->swpar.rchan = 2;
+
+	hdl->fd = fd;
+
+	return hdl;
+}
+
+struct sio_hdl *
+_sio_oss_open(const char *str, unsigned int mode, int nbio)
+{
+	struct sio_oss_hdl *hdl;
+	int fd;
+
+	fd = sio_oss_getfd(str, mode, nbio);
+	if (fd < 0)
+		return NULL;
+
+	hdl = sio_oss_fdopen(fd, mode, nbio);
+	if (hdl != NULL) {
+		hdl->devstr = strdup(str);
+		return (struct sio_hdl*)hdl;
+        }
+	while (close(fd) < 0 && errno == EINTR)
+		; /* retry */
+
+	return NULL;
+}
+
+static void
+sio_oss_close(struct sio_hdl *sh)
+{
+	struct sio_oss_hdl *hdl = (struct sio_oss_hdl *)sh;
+
+	while (close(hdl->fd) < 0 && errno == EINTR)
+		; /* retry */
+	free(hdl->devstr);
+	free(hdl);
+}
+
+static int
+sio_oss_start(struct sio_hdl *sh)
+{
+	struct sio_oss_hdl *hdl = (struct sio_oss_hdl *)sh;
+	int low;
+
+	hdl->obpf = hdl->sio.par.pchan * hdl->sio.par.bps;
+	hdl->ibpf = hdl->sio.par.rchan * hdl->sio.par.bps;
+	hdl->isamples = 0;
+	hdl->osamples = 0;
+	hdl->idelta = 0;
+	hdl->odelta = 0;
+
+	/* Nothing else to do here, device was just (re-)opened in
+	 * sio_setpar and OSS starts playing/recording on first
+	 * write/read.
+	 */
+	_sio_onmove_cb(&hdl->sio, 0);
+
+	return 1;
+}
+
+static int
+sio_oss_stop(struct sio_hdl *sh)
+{
+	struct sio_oss_hdl *hdl = (struct sio_oss_hdl*)sh;
+	/* Close and reopen device.  This resets CURRENT_IPTR which
+	 * allows us to get a semi-accurate recording position */
+        if (sio_oss_audio_setpar(hdl, &hdl->swpar) < 0)
+		return 0;
+	return 1;
+}
+
+static int
+sio_oss_setpar(struct sio_hdl *sh, struct sio_par *par)
+{
+	struct sio_oss_hdl *hdl = (struct sio_oss_hdl *)sh;
+	struct audio_swpar ap;
+
+	AUDIO_INITPAR(&ap);
+	ap.sig = par->sig;
+	ap.le = par->le;
+	ap.bits = par->bits;
+	ap.bps = par->bps;
+	ap.msb = par->msb;
+	ap.rate = par->rate;
+	if (hdl->sio.mode & SIO_PLAY)
+		ap.pchan = par->pchan;
+	if (hdl->sio.mode & SIO_REC)
+		ap.rchan = par->rchan;
+	if (par->round != ~0U && par->appbufsz != ~0U) {
+		ap.round = par->round;
+		ap.nblks = par->appbufsz / par->round;
+	} else if (par->round != ~0U) {
+		ap.round = par->round;
+		ap.nblks = 2;
+	} else if (par->appbufsz != ~0U) {
+		ap.round = par->appbufsz / 2;
+		ap.nblks = 2;
+	}
+	if (sio_oss_audio_setpar(hdl, &ap) < 0) {
+		DPERROR("AUDIO_SETPAR");
+		hdl->sio.eof = 1;
+		return 0;
+	}
+	return 1;
+}
+
+static int
+sio_oss_getpar(struct sio_hdl *sh, struct sio_par *par)
+{
+	struct sio_oss_hdl *hdl = (struct sio_oss_hdl *)sh;
+	struct audio_swpar ap;
+
+	if (sio_oss_audio_getpar(hdl, &ap) < 0) {
+		DPERROR("AUDIO_GETPAR");
+		hdl->sio.eof = 1;
+		return 0;
+	}
+	par->sig = ap.sig;
+	par->le = ap.le;
+	par->bits = ap.bits;
+	par->bps = ap.bps;
+	par->msb = ap.msb;
+	par->rate = ap.rate;
+	par->pchan = ap.pchan;
+	par->rchan = ap.rchan;
+	par->round = ap.round;
+	par->appbufsz = par->bufsz = ap.round * ap.nblks;
+	par->xrun = SIO_IGNORE;
+	return 1;
+}
+
+static size_t
+sio_oss_read(struct sio_hdl *sh, void *buf, size_t len)
+{
+	struct sio_oss_hdl *hdl = (struct sio_oss_hdl *)sh;
+	ssize_t n;
+
+	while ((n = read(hdl->fd, buf, len)) < 0) {
+		if (errno == EINTR)
+			continue;
+		if (errno != EAGAIN) {
+			DPERROR("sio_oss_read: read");
+			hdl->sio.eof = 1;
+		}
+		return 0;
+	}
+	if (n == 0) {
+		DPRINTF("sio_oss_read: eof\n");
+		hdl->sio.eof = 1;
+		return 0;
+	}
+
+	return n;
+}
+
+static size_t
+sio_oss_write(struct sio_hdl *sh, const void *buf, size_t len)
+{
+	struct sio_oss_hdl *hdl = (struct sio_oss_hdl *)sh;
+	const unsigned char *data = buf;
+	ssize_t n, todo;
+
+	todo = len;
+	while ((n = write(hdl->fd, data, todo)) < 0) {
+		if (errno == EINTR)
+			continue;
+		if (errno != EAGAIN) {
+			DPERROR("sio_oss_write: write");
+			hdl->sio.eof = 1;
+		}
+		return 0;
+	}
+
+	return n;
+}
+
+static int
+sio_oss_nfds(struct sio_hdl *hdl)
+{
+	return 1;
+}
+
+static int
+sio_oss_pollfd(struct sio_hdl *sh, struct pollfd *pfd, int events)
+{
+	struct sio_oss_hdl *hdl = (struct sio_oss_hdl *)sh;
+
+	pfd->fd = hdl->fd;
+	pfd->events = events;
+
+	return 1;
+}
+
+int
+sio_oss_revents(struct sio_hdl *sh, struct pollfd *pfd)
+{
+	struct sio_oss_hdl *hdl = (struct sio_oss_hdl *)sh;
+	int delta;
+	int revents = pfd->revents;
+	long long play_pos, rec_pos;
+	oss_count_t optr, iptr;
+
+	if ((pfd->revents & POLLHUP) ||
+	    (pfd->revents & (POLLIN | POLLOUT)) == 0)
+		return pfd->revents;
+
+	if (hdl->sio.mode & SIO_PLAY) {
+		if (ioctl(hdl->fd, SNDCTL_DSP_CURRENT_OPTR, &optr) < 0) {
+			DPERROR("sio_oss_revents: ");
+			hdl->sio.eof = 1;
+			return POLLHUP;
+		}
+		play_pos = optr.samples - optr.fifo_samples;
+		delta = play_pos - hdl->osamples;
+		hdl->osamples = play_pos;
+		hdl->odelta += delta;
+		if (!(hdl->sio.mode & SIO_REC)) {
+			hdl->idelta += delta;
+		}
+	}
+	if (hdl->sio.mode & SIO_REC) {
+		if (ioctl(hdl->fd, SNDCTL_DSP_CURRENT_IPTR, &iptr) < 0) {
+			DPERROR("sio_oss_revents: ");
+			hdl->sio.eof = 1;
+			return POLLHUP;
+		}
+		rec_pos = iptr.samples - iptr.fifo_samples;
+		delta = rec_pos - hdl->isamples;
+		hdl->isamples = rec_pos;
+		hdl->idelta += delta;
+		if (!(hdl->sio.mode & SIO_PLAY)) {
+			hdl->odelta += delta;
+		}
+	}
+
+	delta = (hdl->idelta > hdl->odelta) ? hdl->idelta : hdl->odelta;
+	if (delta > 0) {
+		_sio_onmove_cb(&hdl->sio, delta);
+		hdl->idelta -= delta;
+		hdl->odelta -= delta;
+	}
+	return revents;
+}
+
+static void
+sio_oss_fmt_to_swpar(int fmt, struct audio_swpar *ap) {
+	switch(fmt) {
+	case AFMT_S8:
+		ap->le = 1;
+		ap->sig = 1;
+		ap->bits = 8;
+		break;
+	case AFMT_U8:
+		ap->le = 1;
+		ap->sig = 0;
+		ap->bits = 8;
+		break;
+	case AFMT_S16_LE:
+		ap->le = 1;
+		ap->sig = 1;
+		ap->bits = 16;
+		break;
+	case AFMT_S16_BE:
+		ap->le = 0;
+		ap->sig = 1;
+		ap->bits = 16;
+		break;
+	case AFMT_U16_LE:
+		ap->le = 1;
+		ap->sig = 0;
+		ap->bits = 16;
+		break;
+	case AFMT_U16_BE:
+		ap->le = 0;
+		ap->sig = 0;
+		ap->bits = 16;
+		break;
+	case AFMT_S24_LE:
+		ap->le = 1;
+		ap->sig = 1;
+		ap->bits = 24;
+		break;
+	case AFMT_S24_BE:
+		ap->le = 0;
+		ap->sig = 1;
+		ap->bits = 24;
+		break;
+	case AFMT_U24_LE:
+		ap->le = 1;
+		ap->sig = 0;
+		ap->bits = 24;
+		break;
+	case AFMT_U24_BE:
+		ap->le = 0;
+		ap->sig = 0;
+		ap->bits = 24;
+		break;
+	case AFMT_S32_LE:
+		ap->le = 1;
+		ap->sig = 1;
+		ap->bits = 32;
+		break;
+	case AFMT_S32_BE:
+		ap->le = 0;
+		ap->sig = 1;
+		ap->bits = 32;
+		break;
+	case AFMT_U32_LE:
+		ap->le = 1;
+		ap->sig = 0;
+		ap->bits = 32;
+		break;
+	case AFMT_U32_BE:
+		ap->le = 0;
+		ap->sig = 0;
+		ap->bits = 32;
+		break;
+	}
+}
+
+static int
+sio_oss_swpar_to_fmt(struct audio_swpar *ap)
+{
+	unsigned int bits = ap->bits;
+	unsigned int sig = ap->sig;
+	unsigned int le = ap->le;
+
+	switch(bits) {
+	case 8:
+		if (sig)
+			return AFMT_S8;
+		else
+			return AFMT_U8;
+		break;
+	case 16:
+		if (sig)
+			if (le)
+				return AFMT_S16_LE;
+			else
+				return AFMT_S16_BE;
+		else
+			if (le)
+				return AFMT_U16_LE;
+			else
+				return AFMT_U16_BE;
+		break;
+		break;
+	case 24:
+		if (sig)
+			if (le)
+				return AFMT_S24_LE;
+			else
+				return AFMT_S24_BE;
+		else
+			if (le)
+				return AFMT_U24_LE;
+			else
+				return AFMT_U24_BE;
+		break;
+		break;
+	case 32:
+		if (sig)
+			if (le)
+				return AFMT_S32_LE;
+			else
+				return AFMT_S32_BE;
+		else
+			if (le)
+				return AFMT_U32_LE;
+			else
+				return AFMT_U32_BE;
+		break;
+	default:
+		if (sig)
+			if (SIO_LE_NATIVE)
+				return AFMT_S16_LE;
+			else
+				return AFMT_S16_BE;
+		else
+			if (SIO_LE_NATIVE)
+				return AFMT_U16_LE;
+			else
+				return AFMT_U16_BE;
+	}
+}
+
+static int sio_oss_audio_getpar(struct sio_oss_hdl *hdl, struct audio_swpar *ap)
+{
+	audio_buf_info bi;
+
+	*ap = hdl->swpar;
+
+	return 0;
+}
+
+static int sio_oss_audio_setpar(struct sio_oss_hdl *hdl, struct audio_swpar *ap)
+{
+	audio_buf_info bi;
+	int bufsz;
+	int chan;
+	int fmt;
+	int rate;
+
+	if (sio_oss_reopen(hdl) < 0) {
+		DPERROR("sio_oss_audio_setpar: reopen");
+		return -1;
+	}
+
+	ap->msb = ap->msb == -1 ? 0 : ap->msb;
+	ap->sig = ap->sig == -1 ? 1 : ap->sig;
+	ap->bits = ap->bits == -1 ? ap->bps == -1 ? 16 : ap->bps*8 : ap->bits;
+	ap->le = ap->le == -1 ? SIO_LE_NATIVE : ap->le;
+	ap->bps = ap->bps == -1 ? SIO_BPS(ap->bits) : ap->bps;
+	ap->msb = 0;
+	ap->rate = ap->rate == -1 ? 48000 : ap->rate;
+
+	if (ap->bits < 8)
+		ap->bits = 8;
+	if (ap->bits > 32)
+		ap->bits = 32;
+	if (ap->bps < 1)
+		ap->bps = 1;
+	if (ap->bps > 4)
+		ap->bps = 4;
+	if (ap->rate < 4000)
+		ap->rate = 4000;
+	if (ap->rate > 192000)
+		ap->rate = 192000;
+
+	fmt = sio_oss_swpar_to_fmt(ap);
+	if (fmt < 0)
+		return -1;
+	if (ioctl(hdl->fd, SNDCTL_DSP_SETFMT, &fmt) < 0) {
+		DPERROR("sio_oss_audio_setpar: SETFMT");
+		return -1;
+	}
+	sio_oss_fmt_to_swpar(fmt, ap);
+
+	if (ioctl(hdl->fd, SNDCTL_DSP_SPEED, &ap->rate) < 0) {
+		DPERROR("sio_oss_audio_setpar: SPEED");
+		return -1;
+	}
+
+	chan = ap->pchan == ~0U ? ap->pchan : ap->rchan;
+	chan = chan == -1 ? 2 : chan;
+	if (ioctl(hdl->fd, SNDCTL_DSP_CHANNELS, &chan) < 0) {
+		DPERROR("sio_oss_audio_setpar: CHANNELS");
+		return -1;
+	}
+	ap->pchan = ap->rchan = chan;
+
+	ap->nblks = ap->nblks <= 0 ? 8 : ap->nblks;
+	ap->round = ap->round <= 0 ? 960 : ap->round;
+
+	hdl->swpar = *ap;
+
+	return 0;
+}
+
+static int sio_oss_reopen(struct sio_oss_hdl *hdl) {
+	/* Reopen device */
+	while (close(hdl->fd) < 0 && errno == EINTR)
+		; /* retry */
+	hdl->fd = sio_oss_getfd(hdl->devstr, hdl->sio.mode, 1);
+	if (hdl->fd < 0) {
+		DPERROR("sio_oss_audio_setpar: reopen");
+		return -1;
+	}
+	return 0;
+}
+
+#endif /* defined USE_OSS */
