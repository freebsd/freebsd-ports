/*
 * Copyright (c) 2008 Jacob Meuser <jakemsr@sdf.lonestar.org>
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

#include "SDL_config.h"

/* Allow access to a raw mixing buffer */

#ifdef HAVE_SIGNAL_H
#include <signal.h>
#endif
#include <unistd.h>

#include "SDL_timer.h"
#include "SDL_audio.h"
#include "../SDL_audiomem.h"
#include "../SDL_audio_c.h"
#include "../SDL_audiodev_c.h"
#include "SDL_sndioaudio.h"

/* The tag name used by sndio audio */
#define SNDIO_DRIVER_NAME         "sndio"

/* Audio driver functions */
static int SNDIO_OpenAudio(_THIS, SDL_AudioSpec *spec);
static void SNDIO_WaitAudio(_THIS);
static void SNDIO_PlayAudio(_THIS);
static Uint8 *SNDIO_GetAudioBuf(_THIS);
static void SNDIO_CloseAudio(_THIS);

/* Audio driver bootstrap functions */

static int Audio_Available(void)
{
	struct sio_hdl *this_hdl;
	int available = 0;

	if ( (this_hdl = sio_open(SIO_DEVANY, SIO_PLAY, 0)) != NULL ) {
		sio_close(this_hdl);
		available = 1;
	}

	return available;
}

static void Audio_DeleteDevice(SDL_AudioDevice *device)
{
	SDL_free(device->hidden);
	SDL_free(device);
}

static SDL_AudioDevice *Audio_CreateDevice(int devindex)
{
	SDL_AudioDevice *this;

	/* Initialize all variables that we clean on shutdown */
	this = (SDL_AudioDevice *)SDL_malloc(sizeof(SDL_AudioDevice));
	if ( this ) {
		SDL_memset(this, 0, (sizeof *this));
		this->hidden = (struct SDL_PrivateAudioData *)
				SDL_malloc((sizeof *this->hidden));
	}
	if ( (this == NULL) || (this->hidden == NULL) ) {
		SDL_OutOfMemory();
		if ( this ) {
			SDL_free(this);
		}
		return(0);
	}
	SDL_memset(this->hidden, 0, (sizeof *this->hidden));

	/* Set the function pointers */
	this->OpenAudio = SNDIO_OpenAudio;
	this->WaitAudio = SNDIO_WaitAudio;
	this->PlayAudio = SNDIO_PlayAudio;
	this->GetAudioBuf = SNDIO_GetAudioBuf;
	this->CloseAudio = SNDIO_CloseAudio;

	this->free = Audio_DeleteDevice;

	hdl = NULL;

	return this;
}

AudioBootStrap SNDIO_bootstrap = {
	SNDIO_DRIVER_NAME, "sndio",
	Audio_Available, Audio_CreateDevice
};



/* This function waits until it is possible to write a full sound buffer */
static void SNDIO_WaitAudio(_THIS)
{
	/* nothing, we're using the blocking api */
}

static void SNDIO_PlayAudio(_THIS)
{
	int written;

	/* Write the audio data */
	written = sio_write(hdl, mixbuf, mixlen);
	
	/* If we couldn't write, assume fatal error for now */
	if ( written == 0 ) {
		this->enabled = 0;
	}
#ifdef DEBUG_AUDIO
	fprintf(stderr, "Wrote %d bytes of audio data\n", written);
#endif
}

static Uint8 *SNDIO_GetAudioBuf(_THIS)
{
	return(mixbuf);
}

static void SNDIO_CloseAudio(_THIS)
{
	if ( mixbuf != NULL ) {
		SDL_FreeAudioMem(mixbuf);
		mixbuf = NULL;
	}
	if ( hdl != NULL ) {
		sio_close(hdl);
		hdl = NULL;
	}
}

static int SNDIO_OpenAudio(_THIS, SDL_AudioSpec *spec)
{
	struct sio_par par;

	mixbuf = NULL;

	if ((hdl = sio_open(NULL, SIO_PLAY, 0)) == NULL) {
		SDL_SetError("sio_open() failed");
		return(-1);
	}

	sio_initpar(&par);

	switch (spec->format) {
	case AUDIO_S16LSB:
		par.bits = 16;
		par.sig = 1;
		par.le = 1;
		break;
	case AUDIO_S16MSB:
		par.bits = 16;
		par.sig = 1;
		par.le = 0;
		break;
	case AUDIO_S8:
		par.bits = 8;
		par.sig = 1;
		break;
	case AUDIO_U16LSB:
		par.bits = 16;
		par.sig = 0;
		par.le = 1;
		break;
	case AUDIO_U16MSB:
		par.bits = 16;
		par.sig = 0;
		par.le = 0;
		break;
	case AUDIO_U8:
		par.bits = 8;
		par.sig = 0;
		break;
	default:
		SDL_SetError("SNDIO unknown format");
		return(-1);
	}

	par.rate = spec->freq;
	par.pchan = spec->channels;
	par.round = spec->samples;
	par.appbufsz = par.round * 2;

	if (sio_setpar(hdl, &par) == 0) {
		SDL_SetError("sio_setpar() failed");
		return(-1);
	}

	if (sio_getpar(hdl, &par) == 0) {
		SDL_SetError("sio_getpar() failed");
		return(-1);
	}

	if (par.bits == 16) {
		if (par.sig && par.le) {
			spec->format = AUDIO_S16LSB;
		} else if (par.sig && !par.le) {
			spec->format = AUDIO_S16MSB;
		} else if (!par.sig && par.le) {
			spec->format = AUDIO_U16LSB;
		} else 
			spec->format = AUDIO_U16MSB;
	} else if (par.bits == 8) {
		spec->format = par.sig ? AUDIO_S8 : AUDIO_U8;
	} else {
		SDL_SetError("SNDIO couldn't configure a suitable format");
		return(-1);
	}

	spec->freq = par.rate;
	spec->channels = par.pchan;
	spec->samples = par.round;

	SDL_CalculateAudioSpec(spec);

	/* Allocate mixing buffer */
	mixlen = spec->size;
	mixbuf = (Uint8 *)SDL_AllocAudioMem(mixlen);
	if ( mixbuf == NULL ) {
		return(-1);
	}
	SDL_memset(mixbuf, spec->silence, spec->size);

	if ( sio_start(hdl) == 0 ) {
		SDL_SetError("sio_start() failed");
		return(-1);
	}

	/* We're ready to rock and roll. :-) */
	return(0);
}
