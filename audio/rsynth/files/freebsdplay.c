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

/* Audio Parameters */

static int dev_fd = -1;
 /* file descriptor for audio device */
char *dev_file = "/dev/dsp";

static int linear_fd = -1;

static char *linear_file = NULL;

char *prog = "hplay";

static int
audio_open(void)
{
 dev_fd = open(dev_file, O_WRONLY | O_NDELAY);
 if (dev_fd < 0)
  {
   perror(dev_file);
   return 0;
  }
 return 1;
}

int
audio_init(int argc, char *argv[])
{
 int rate_set = 0;
 int use_audio = 1;

 prog = argv[0];

 argc = getargs("freebsd Audio",argc, argv,
                "r", "%d", &rate_set,    "Sample rate",
                "a", NULL, &use_audio,   "Audio enable",
                NULL);

 if (help_only)
  return argc;

 if (use_audio)
  audio_open();

 if (rate_set)
  samp_rate = rate_set;

 if (dev_fd > 0)
  {
   ioctl(dev_fd, SNDCTL_DSP_SPEED, &samp_rate);
   printf("Actual sound rate: %ld\n", samp_rate);
  }

 return argc;
}

void
audio_term()
{
 int dummy;

 /* Close audio system  */
 if (dev_fd >= 0)
  {
   ioctl(dev_fd, SNDCTL_DSP_SYNC, &dummy);
   close(dev_fd);
   dev_fd = -1;
  }

 /* Finish linear file */
 if (linear_fd >= 0)
  {
   ftruncate(linear_fd, lseek(linear_fd, 0L, SEEK_CUR));
   close(linear_fd);
   linear_fd = -1;
  }
}

void
audio_play(int n, short *data)
{
 if (n > 0)
  {
   unsigned char *converted = (unsigned char *) malloc(n);
   int i;

   if (converted == NULL)
    {
     fprintf(stderr, "Could not allocate memory for conversion\n");
     exit(3);
    }

   for (i = 0; i < n; i++)
    converted[i] = (data[i] - 32768) / 256;

   if (linear_fd >= 0)
    {
     if (write(linear_fd, converted, n) != n)
      perror("write");
    }

   if (dev_fd >= 0)
    {
     if (write(dev_fd, converted, n) != n)
      perror("write");
    }

   free(converted);
  }
}
