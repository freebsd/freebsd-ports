#include <config.h>

/*****************************************************************/
/***                                                           ***/
/***    Play out a file on FreeBSD                             ***/
/***	(conf/linuxplay.c with changes)                        ***/
/***                                                           ***/
/*****************************************************************/

#include <useconfig.h>
#include <stdio.h>
#include <math.h>
#include <errno.h>
#include <ctype.h>

#include <fcntl.h>
#include <sys/file.h>
#include <sys/stat.h>
#include <sys/param.h>
#include <sys/signal.h>

#include <sys/ioctl.h>

#include <sys/soundcard.h>
#include "proto.h"
#include "getargs.h"
#include "hplay.h"

#define SAMP_RATE 8000
long samp_rate = SAMP_RATE;

static int dev_fd = -1;
char *dev_file = "/dev/dsp";

char *prog = "hplay";

int
audio_init(int argc, char *argv[])
{
 int rate_set = 0;
 int use_audio = 1;
 int fmt;

 prog = argv[0];

 argc = getargs("Audio output",argc, argv,
                "r", "%d", &rate_set,    "Sample rate",
                "a", NULL, &use_audio,   "Audio enable",
                NULL);

 if (help_only || !use_audio)
  return argc;

 dev_fd = open(dev_file, O_WRONLY);
 if (dev_fd < 0) {
  perror(dev_file);
  return argc;
 }

 if (rate_set)
  samp_rate = rate_set;

 fmt = AFMT_S16_NE;
 if (ioctl(dev_fd, SNDCTL_DSP_SETFMT, &fmt) < 0)
  perror("SNDCTL_DSP_SETFMT");

 if (ioctl(dev_fd, SNDCTL_DSP_SPEED, &samp_rate) < 0)
  perror("SNDCTL_DSP_SPEED");

 return argc;
}

void
audio_term()
{
 if (dev_fd >= 0)
  {
   close(dev_fd);
   dev_fd = -1;
  }
}

void
audio_play(int n, short *data)
{
 if (n > 0 && dev_fd >= 0)
  {
   size_t size = n * sizeof(short);
   if (write(dev_fd, data, size) != size)
    perror("write");
  }
}
