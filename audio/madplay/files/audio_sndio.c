/*	$OpenBSD: audio_sndio.c,v 1.2 2009/06/20 14:56:18 martynas Exp $	*/

/*
 * Copyright (c) 2009 Martynas Venckus <martynas@openbsd.org>
 *
 * Permission to use, copy, modify, and distribute this software for any
 * purpose with or without fee is hereby granted, provided that the above
 * copyright notice and this permission notice appear in all copies.
 *
 * THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES
 * WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF
 * MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR
 * ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES
 * WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN
 * ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF
 * OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
 */

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "global.h"
#include "gettext.h"
#include "audio.h"

#include <sndio.h>

static audio_pcmfunc_t *audio_pcm;
static struct sio_hdl *hdl;
static int sio_started;

static int
init(struct audio_init *init)
{
	hdl = sio_open((char *)init->path, SIO_PLAY, 0);
	if (hdl == NULL) {
		audio_error = ":";
		return (-1);
	}

	return (0);
}

static int
config(struct audio_config *config)
{
	struct sio_par par;
	unsigned int bitdepth;

	bitdepth = config->precision & ~7;
	if (bitdepth == 0) {
		bitdepth = 16;
	} else if (bitdepth > 32) {
		bitdepth = 32;
	}

	sio_initpar(&par);
	par.bits = bitdepth;
	par.le = SIO_LE_NATIVE;
	par.pchan = config->channels;
	par.rate = config->speed;
	par.sig = (par.bits == 8) ? 0 : 1;

	if (sio_started) {
		sio_stop(hdl);
		sio_started = 0;
	}

	if (!sio_setpar(hdl, &par) || !sio_getpar(hdl, &par) ||
		!sio_start(hdl)) {
		audio_error = ":sio_setpar";
		sio_close(hdl);
		return (-1);
	}

	sio_started = 1;

	switch(par.bits) {
	case 8:
		audio_pcm = audio_pcm_u8;
		break;
	case 16:
		audio_pcm = par.le ? audio_pcm_s16le : audio_pcm_s16be;
		break;
	case 24:
		audio_pcm = par.le ? audio_pcm_s32le : audio_pcm_s32be;
		break;
	case 32:
		audio_pcm = par.le ? audio_pcm_s32le : audio_pcm_s32be;
		break;
	default:
		audio_error = _("no supported audio format available");
		sio_close(hdl);
		return (-1);
	}

	config->channels = par.pchan;
	config->precision = par.bits;
	config->speed = par.rate;

	return (0);
}

static int
play(struct audio_play *play)
{
	unsigned char data[MAX_NSAMPLES * 4 * 2];
	unsigned int len;
	int count;

	len = audio_pcm(data, play->nsamples, play->samples[0],
		play->samples[1], play->mode, play->stats);

	count = (int)sio_write(hdl, data, len);
	if (count == 0 && sio_eof(hdl))
		return (-1);

	return (count);
}

static int
stop(struct audio_stop *stop)
{
	return (0);
}

static int
finish(struct audio_finish *finish)
{
	sio_close(hdl);

	return (0);
}

int
audio_sndio(union audio_control *control)
{
	audio_error = 0;

	switch (control->command) {
	case AUDIO_COMMAND_INIT:
		return (init(&control->init));

	case AUDIO_COMMAND_CONFIG:
		return (config(&control->config));

	case AUDIO_COMMAND_PLAY:
		return (play(&control->play));

	case AUDIO_COMMAND_STOP:
		return (stop(&control->stop));

	case AUDIO_COMMAND_FINISH:
		return (finish(&control->finish));
	}

	return (0);
}

