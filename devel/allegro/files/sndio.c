/*
 * Copyright (c) 2010 Jacob Meuser <jakemsr@sdf.lonestar.org>
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


#include "allegro.h"

#if (defined ALLEGRO_WITH_SNDIODIGI) && ((!defined ALLEGRO_WITH_MODULES) || (defined ALLEGRO_MODULE))

#include "allegro/internal/aintern.h"
#include "allegro/platform/aintunix.h"

#include <stdlib.h>
#include <stdio.h>
#include <limits.h>
#include <unistd.h>
#include <poll.h>
#include <sndio.h>

static int sndio_detect(int input);
static int sndio_init(int input, int voices);
static void sndio_exit(int input);
static int sndio_set_mixer_volume(int volume);
static int sndio_get_mixer_volume(void);

static int sndio_buffer_size(void);

static int sndio_rec_cap_rate(int bits, int stereo);
static int sndio_rec_cap_parm(int rate, int bits, int stereo);
static int sndio_rec_source(int source);
static int sndio_rec_start(int rate, int bits, int stereo);
static void sndio_rec_stop(void);
static int sndio_rec_read(void *buf);

static int open_sndio_device(int input);
static void sndio_update(int threaded);
static void movecb(void *addr, int delta);
static void volcb(void *addr, unsigned vol);

static struct sio_hdl *hdl;
static struct sio_par par;
static int sndio_signed;
static int sndio_play_bufsize, sndio_play_round, sndio_play_appbufsz;
static unsigned char *sndio_play_bufdata;
static char sndio_desc[256] = EMPTY_STRING;
long long sndio_realpos, sndio_playpos;
int sndio_volume;

static int sndio_save_bits, sndio_save_stereo, sndio_save_freq;
static int sndio_rec_bufsize, sndio_rec_round, sndio_rec_appbufsz;
static unsigned char *sndio_rec_bufdata;

DIGI_DRIVER digi_sndio =
{
	DIGI_SNDIO,
	empty_string,
	empty_string,
	"sndio",
	0,
	0,
	MIXER_MAX_SFX,
	MIXER_DEF_SFX,

	/* setup routines */
	sndio_detect,
	sndio_init,
	sndio_exit,
	sndio_set_mixer_volume,
	sndio_get_mixer_volume,

	/* for use by the audiostream functions */
	NULL,
	NULL,
	sndio_buffer_size,

	/* voice control functions */
	_mixer_init_voice,
	_mixer_release_voice,
	_mixer_start_voice,
	_mixer_stop_voice,
	_mixer_loop_voice,

	/* position control functions */
	_mixer_get_position,
	_mixer_set_position,

	/* volume control functions */
	_mixer_get_volume,
	_mixer_set_volume,
	_mixer_ramp_volume,
	_mixer_stop_volume_ramp,

	/* pitch control functions */
	_mixer_get_frequency,
	_mixer_set_frequency,
	_mixer_sweep_frequency,
	_mixer_stop_frequency_sweep,

	/* pan control functions */
	_mixer_get_pan,
	_mixer_set_pan,
	_mixer_sweep_pan,
	_mixer_stop_pan_sweep,

	/* effect control functions */
	_mixer_set_echo,
	_mixer_set_tremolo,
	_mixer_set_vibrato,

	/* input functions */
	0,
	0,
	sndio_rec_cap_rate,
	sndio_rec_cap_parm,
	sndio_rec_source,
	sndio_rec_start,
	sndio_rec_stop,
	sndio_rec_read
};


/* used to probe and to configure the device.  don't use sio_start() here. */
static int
open_sndio_device(int input)
{
	hdl = sio_open(NULL, (input ? SIO_REC : SIO_PLAY), 0);
	if (hdl == NULL) {
		uszprintf(allegro_error, ALLEGRO_ERROR_SIZE,
		    get_config_text("sio_opn failed"));
		return -1;
	}

	sio_initpar(&par);
	par.bits = (_sound_bits == 8) ? 8 : 16;
	par.sig = (_sound_bits == 8) ? 0 : 1;
	if (input)
		par.rchan = (_sound_stereo) ? 2 : 1;
	else
		par.pchan = (_sound_stereo) ? 2 : 1;
	par.rate = (_sound_freq > 0) ? _sound_freq : 48000;
	par.le = SIO_LE_NATIVE;
	/* allegro wants small blocks */
	par.round = 512;
	par.appbufsz = par.rate / 10;

	if (!sio_setpar(hdl, &par) || !sio_getpar(hdl, &par) ||
	    (par.bits != 8 && par.bits != 16) ||
	    (par.bits == 8 && par.sig) ||
	    (par.bits == 16 && !par.sig) ||
	    (par.bits == 16 && par.le != SIO_LE_NATIVE) ||
	    (input && (par.rchan != 1 && par.rchan != 2)) ||
	    (!input && (par.pchan != 1 && par.pchan != 2))) {
		ustrzcpy(allegro_error, ALLEGRO_ERROR_SIZE,
		    get_config_text("could not set sndio parameters"));
		sio_close(hdl);
		return -1;
	}

	_sound_bits = par.bits;
	_sound_stereo = input ? par.rchan == 2 : par.pchan == 2;
	_sound_freq = par.rate;

	if (input) {
		sndio_rec_round = par.round; 
		sndio_rec_appbufsz = par.appbufsz;
		sndio_rec_bufsize = par.round * par.bps * par.rchan;
	} else {
		sndio_play_round = par.round;
		sndio_play_appbufsz = par.appbufsz;
		sndio_play_bufsize = sndio_play_round * par.bps * par.pchan;
	}
	sndio_signed = par.sig ? 1 : 0;

	return 0;
}


static int
sndio_detect(int input)
{
	if (input) {
		if (digi_driver != digi_input_driver) {
			ustrzcpy(allegro_error, ALLEGRO_ERROR_SIZE,
			    get_config_text("sndio output driver must be installed before input can be read"));
			return FALSE;
		}
		return TRUE;
	}

	if (open_sndio_device(0) != 0)
		return FALSE;

	sio_close(hdl);
	return TRUE;
}


/* number of samples per channel in a block */
static int
sndio_buffer_size(void)
{
	return sndio_play_round;
}


/* callback for data movement notification */ 
static void
movecb(void *addr, int delta)
{
	sndio_realpos += delta;
}


/* callback for volume change notification */ 
static void
volcb(void *addr, unsigned vol)
{
	sndio_volume = vol;
}


/* write as many blocks as is currently possible */
static void
sndio_update(int threaded)
{
	struct pollfd pfd;
	nfds_t nfds;
	int i, nblocks, nbytes;

	/* make sure counters have been updated */
	nfds = sio_pollfd(hdl, &pfd, POLLOUT);
	poll(&pfd, nfds, 0);
	if (!(sio_revents(hdl, &pfd) & POLLOUT))
		return;

	nblocks = (sndio_play_appbufsz - (sndio_playpos - sndio_realpos)) /
	    sndio_play_round;

	/* we got POLLOUT, so we can write something.  if we don't
	 * write anything, we could underrun.
	 */
	if (nblocks < 1)
		nblocks = 1;

	for (i = 0; i < nblocks; i++) {
		sio_write(hdl, sndio_play_bufdata, sndio_play_bufsize);
		sndio_playpos += sndio_play_round;
		if (sio_eof(hdl)) {
			/* print error message? */
			return;
		}
		_mix_some_samples((uintptr_t) sndio_play_bufdata, 0, sndio_signed);
	}
}


static int
sndio_init(int input, int voices)
{
	char tmp1[128], tmp2[128];

	if (input) {
		digi_driver->rec_cap_bits = 16;
		digi_driver->rec_cap_stereo = TRUE;
		return 0;
	}

	if (open_sndio_device(0) != 0)
		return -1;

	sndio_play_bufdata = _AL_MALLOC_ATOMIC(sndio_play_bufsize);
	if (sndio_play_bufdata == 0) {
		ustrzcpy(allegro_error, ALLEGRO_ERROR_SIZE,
		    get_config_text("Can not allocate audio buffer"));
		sio_close(hdl);
		return -1;
	}

	sndio_realpos = sndio_playpos = 0;
	sio_onmove(hdl, movecb, NULL);

	sndio_volume = 127;
	sio_onvol(hdl, volcb, NULL);

	if (!sio_start(hdl)) {
		ustrzcpy(allegro_error, ALLEGRO_ERROR_SIZE,
		    get_config_text("Can not start sndio"));
		sio_close(hdl);
		return -1;
	}

	digi_sndio.voices = voices;

	/* first arg is total number of samples */
	if (_mixer_init(sndio_play_round * (_sound_stereo ? 2 : 1),
	    _sound_freq, _sound_stereo, ((_sound_bits == 16) ? 1 : 0),
	    &digi_sndio.voices) != 0) {
		ustrzcpy(allegro_error, ALLEGRO_ERROR_SIZE,
		    get_config_text("Can not init software mixer"));
		sio_close(hdl);
		return -1;
	}

	_mix_some_samples((uintptr_t) sndio_play_bufdata, 0, sndio_signed);

	/* Add audio interrupt.  */
	_unix_bg_man->register_func(sndio_update);

	uszprintf(sndio_desc, sizeof(sndio_desc),
	    get_config_text("%s: %d bits, %s, %d Hz, %s"),
	    "sndio device",
	    _sound_bits,
	    uconvert_ascii((sndio_signed ? "signed" : "unsigned"), tmp1),
	    _sound_freq,
	    uconvert_ascii((par.pchan == 2 ? "stereo" : "mono"), tmp2));

	digi_driver->desc = sndio_desc;

	return 0;
}


static void
sndio_exit(int input)
{
	if (input)
		return;

	_unix_bg_man->unregister_func(sndio_update);

	_AL_FREE(sndio_play_bufdata);
	sndio_play_bufdata = 0;

	_mixer_exit();

	if (hdl != NULL)
		sio_close(hdl);
	hdl = NULL;
}


/* 'volume' is 0-255 */
static int
sndio_set_mixer_volume(int volume)
{
	if (!sio_setvol(hdl, volume / 2))
		return -1;

	return 0;
}


/* should return 0-255 */
static int
sndio_get_mixer_volume(void)
{
	return sndio_volume * 2;
}


/*  Returns maximum recording sampling rate. */
static int
sndio_rec_cap_rate(int bits, int stereo)
{
	/* should use sio_getcap() */
	return 48000;
}


/* Returns whether the specified parameters can be set. */
static int
sndio_rec_cap_parm(int rate, int bits, int stereo)
{
	/* should use sio_getcap() */
	return 1;
}


/* Sets the sampling source for audio recording. */
static int
sndio_rec_source(int source)
{
	/* not implemented in sndio */

	switch (source) {
	case SOUND_INPUT_MIC:
		break;
	case SOUND_INPUT_LINE:
		break;
	case SOUND_INPUT_CD:
		break;
	default:
		return -1;
   }

   return 0;
}


/*
 *  Re-opens device with read-mode and starts recording (half-duplex).
 *  Returns the DMA buffer size if successful.
 */
static int
sndio_rec_start(int rate, int bits, int stereo)
{
	sndio_save_bits = _sound_bits;
	sndio_save_stereo = _sound_stereo;
	sndio_save_freq = _sound_freq;

	_unix_bg_man->unregister_func(sndio_update);

	if (hdl != NULL)
		sio_close(hdl);
	hdl = NULL;

	_sound_bits = bits;
	_sound_stereo = stereo;
	_sound_freq = rate;

	if (open_sndio_device(1) != 0)
		return 0;

	sndio_volume = 127;
	sio_onvol(hdl, volcb, NULL);

	if (!sio_start(hdl)) {
		ustrzcpy(allegro_error, ALLEGRO_ERROR_SIZE,
		    get_config_text("Can not start sndio for recording"));
		sio_close(hdl);
		return 0;
	}

	return sndio_rec_bufsize;
}


/* Stops recording and switches the device back to the original mode. */
static void
sndio_rec_stop(void)
{
	if (hdl != NULL)
		sio_close(hdl);
	hdl = NULL;

	_sound_bits = sndio_save_bits;
	_sound_stereo = sndio_save_stereo;
	_sound_freq = sndio_save_freq;

	if (open_sndio_device(0) != 0)
		return;

	sndio_realpos = sndio_playpos = 0;
	sio_onmove(hdl, movecb, NULL);

	sndio_volume = 127;
	sio_onvol(hdl, volcb, NULL);

	if (!sio_start(hdl)) {
		ustrzcpy(allegro_error, ALLEGRO_ERROR_SIZE,
		    get_config_text("Can not start sndio"));
		sio_close(hdl);
		return;
	}

	_unix_bg_man->register_func(sndio_update);
}


/* Retrieves the just recorded buffer, if there is one. */
static int
sndio_rec_read(void *buf)
{
	struct pollfd pfd;
	nfds_t nfds;
	int ret, nbytes, offset = 0;

	/* make sure counters have been updated */
	nfds = sio_pollfd(hdl, &pfd, POLLIN);
	poll(&pfd, nfds, 0);
	sio_revents(hdl, &pfd);
	if (!(sio_revents(hdl, &pfd) & POLLIN))
		return 0;

	nbytes = sndio_rec_bufsize;
	while (nbytes) {
		ret = sio_read(hdl, buf + offset, nbytes);
		if (sio_eof(hdl))
			return 0;
		offset += ret;
		nbytes -= ret;
	}

	return 1;
}

#endif	/* ALLEGRO_WITH_SNDIODIGI */
