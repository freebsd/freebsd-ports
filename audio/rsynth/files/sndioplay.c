#include <config.h>

/*****************************************************************/
/***                                                           ***/
/***    Play out a file on OpenBSD                             ***/
/***	(conf/linuxplay.c with changes)                        ***/
/***                                                           ***/
/*****************************************************************/

#include <useconfig.h>
#include <stdio.h>
#include <math.h>
#include <ctype.h>

#include <sys/file.h>
#include <sys/stat.h>
#include <sys/param.h>
#include <sys/signal.h>

#include <sndio.h>

#include "proto.h"
#include "getargs.h"
#include "hplay.h"

#define SAMP_RATE 8000
long samp_rate = SAMP_RATE;

static struct sio_hdl *hdl;
static struct sio_par par;

char *prog = "hplay";

int
audio_init(int argc, char *argv[])
{
 int rate_set = 0;
 int use_audio = 1;

 prog = argv[0];

 argc = getargs("Audio output",argc, argv,
                "r", "%d", &rate_set,    "Sample rate",
                "a", NULL, &use_audio,   "Audio enable",
                NULL);

 if (help_only)
  return argc;

 if (rate_set)
  samp_rate = rate_set;

 if (!use_audio)
  return argc;

 hdl = sio_open(NULL, SIO_PLAY, 0);
 if (hdl == NULL)
  {
   fprintf(stderr, "sio_open failed\n");
   return argc;
  }

 sio_initpar(&par);
 par.bits = 16;
 par.sig = 1;
 par.le = SIO_LE_NATIVE;
 par.rate = samp_rate;
 par.pchan = 1;

 if (!sio_setpar(hdl, &par) || !sio_getpar(hdl, &par))
  {
   fprintf(stderr, "error setting sndio parameters\n");
   hdl = NULL;
  }

 if (par.bits != 16 || par.le != SIO_LE_NATIVE || par.sig != 1 || par.pchan != 1)
  {
   fprintf(stderr, "returned incorrect sndio parameters\n");
   hdl = NULL;
  }

 samp_rate = par.rate;

 if (hdl && !sio_start(hdl))
  {
   fprintf(stderr, "error starting sndio\n");
   hdl = NULL;
  }

 return argc;
}

void
audio_term()
{
 if (hdl)
  {
   sio_close(hdl);
   hdl = NULL;
  }
}

void
audio_play(int n, short *data)
{
 if (n > 0 && hdl)
  {
   size_t size = n * sizeof(short);
   if (sio_write(hdl, data, size) != size)
    fprintf(stderr, "sio_write: short write");
  }
}
