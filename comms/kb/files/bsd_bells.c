#ifdef DEBUG_BELLS
#include <stdio.h>
#include <stdlib.h>
#include <dev/speaker/speaker.h>
#include <fcntl.h>
#include "kb_bells.h"
#define MAX_BELLS (SPEED_CHANGE_SOUND+1)
int fd_bells;

static void bsd_play_bells(int isound);
main()
{
  int i;
  fd_bells = open("/dev/speaker",O_RDWR);

  if(fd_bells<0) {
    fprintf(stderr,"kldload speaker.ko\n");
    exit(-1);
  }

  for(i=1;i < MAX_BELLS;i++) {
    printf("%d \n", i);
    bsd_play_bells(i);
    getchar();
  }
}
#endif

static void bsd_play_bells(int isound)
{
  tone_t tones;

  switch(isound)
    {
    case BELL_SOUND :
     play_bell_sound ();
     break;
    case DUPE_SOUND :
     play_dupe_sound ();
     break;
    case MESSAGE_SOUND :
     play_message_sound ();
     break;
    case BAND_CHANGE_SOUND :
     play_band_change_sound ();
     break;
    case SINGLE_MULT_SOUND :
     play_single_mult_sound ();
     break;
    case DOUBLE_MULT_SOUND :
     play_double_mult_sound ();
     break;
    case BAD_CALL_SOUND :
     play_bad_call_sound ();
     break;
    case BAD_KEY_SOUND :
     play_bad_key_sound ();
     break;
    case SPEED_CHANGE_SOUND :
     play_speed_change_sound ();
     break;
    default:
      break;
    }
}
#define DELAY_TO_HZ(x)	(x/4)
play_bell_sound()
{
  tone_t tones;
  tones.frequency = DELAY_TO_HZ(0x474);
  tones.duration = 6;
  ioctl(fd_bells, SPKRTONE, &tones);
}
play_dupe_sound ()
{
  tone_t tones;
  tones.frequency = DELAY_TO_HZ(0xfe0);
  tones.duration = 12;
  ioctl(fd_bells, SPKRTONE, &tones);
  tones.frequency = DELAY_TO_HZ(0x17c8);
  tones.duration = 12;
  ioctl(fd_bells, SPKRTONE, &tones);
}
play_message_sound()
{
  tone_t tones;
  tones.frequency = DELAY_TO_HZ(0xd58);
  tones.duration = 12;
  ioctl(fd_bells, SPKRTONE, &tones);
  tones.frequency = DELAY_TO_HZ(0x8e8);
  tones.duration = 12;
  ioctl(fd_bells, SPKRTONE, &tones);
  tones.frequency = DELAY_TO_HZ(0xd58);
  tones.duration = 12;
  ioctl(fd_bells, SPKRTONE, &tones);
}
play_band_change_sound()
{
  tone_t tones;
  tones.frequency = DELAY_TO_HZ(0x710);
  tones.duration = 6;
  ioctl(fd_bells, SPKRTONE, &tones);
  tones.frequency = 0;
  tones.duration = 6;
  ioctl(fd_bells, SPKRTONE, &tones);
  tones.frequency = DELAY_TO_HZ(0x710);
  tones.duration = 6;
  ioctl(fd_bells, SPKRTONE, &tones);
  tones.frequency = 0;
  tones.duration = 6;
  ioctl(fd_bells, SPKRTONE, &tones);
}
play_single_mult_sound()
{
  tone_t tones;
  tones.frequency = DELAY_TO_HZ(0x8e8);
  tones.duration = 6;
  ioctl(fd_bells, SPKRTONE, &tones);
  tones.frequency = DELAY_TO_HZ(0x6ac);
  tones.duration = 6;
  ioctl(fd_bells, SPKRTONE, &tones);
}
play_double_mult_sound()
{
  tone_t tones;
  tones.frequency = DELAY_TO_HZ(0x8e8);
  tones.duration = 6;
  ioctl(fd_bells, SPKRTONE, &tones);
  tones.frequency = DELAY_TO_HZ(0x6ac);
  tones.duration = 6;
  ioctl(fd_bells, SPKRTONE, &tones);
  tones.frequency = 0;
  tones.duration = 6;
  ioctl(fd_bells, SPKRTONE, &tones);
  tones.frequency = DELAY_TO_HZ(0x8e8);
  tones.duration = 6;
  ioctl(fd_bells, SPKRTONE, &tones);
  tones.frequency = DELAY_TO_HZ(0x6ac);
  tones.duration = 6;
  ioctl(fd_bells, SPKRTONE, &tones);
}
play_bad_call_sound ()
{
  tone_t tones;
  tones.frequency = DELAY_TO_HZ(0x11d0);
  tones.duration = 38;
  ioctl(fd_bells, SPKRTONE, &tones);
}
play_bad_key_sound()
{
  tone_t tones;
  tones.frequency = DELAY_TO_HZ(0x17cc);
  tones.duration = 42;
  ioctl(fd_bells, SPKRTONE, &tones);
}
play_speed_change_sound()
{
  tone_t tones;
  tones.frequency = DELAY_TO_HZ(0x710);
  tones.duration = 6;
  ioctl(fd_bells, SPKRTONE, &tones);
}

