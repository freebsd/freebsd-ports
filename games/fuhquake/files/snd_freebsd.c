#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/ioctl.h>
#include <sys/mman.h>
#include <sys/shm.h>
#include <sys/wait.h>
#if defined(__linux__)
#include <linux/soundcard.h>
#elif defined(__FreeBSD__)
#include <sys/soundcard.h>
#endif
#include <stdio.h>

#include "quakedef.h"
#include "sound.h"

int audio_fd;
int snd_inited;
const char *snddev = "/dev/dsp";

static int tryrates[] = { 11025, 22051, 44100, 8000 };

qboolean
SNDDMA_Init(void)
{
	int tmp;
	char *s;
	struct audio_buf_info info;

	snd_inited = 0;

	if (s = getenv("SNDDEV"))
		snddev = s;
	if (tmp = COM_CheckParm("-snddev"))
		snddev = com_argv[tmp + 1];

	/*
	 * Open audio device, confirm capability to mmap,
	 * and get size of DMA buffer.
	 */

	if ((audio_fd = open(snddev, O_RDWR)) < 0)
	{
		perror(snddev);
		Com_Printf("Could not open %s\n", snddev);
		return (0);
	}

	if (ioctl(audio_fd, SNDCTL_DSP_RESET, 0) < 0)
	{
		perror(snddev);
		Com_Printf("Could not reset %s\n", snddev);
		close(audio_fd);
		return (0);
	}

	if (ioctl(audio_fd, SNDCTL_DSP_GETCAPS, &tmp) == -1)
	{
		perror(snddev);
		Com_Printf("Sound driver too old\n");
		close(audio_fd);
		return (0);
	}

	if (!(tmp & DSP_CAP_TRIGGER) || !(tmp & DSP_CAP_MMAP))
	{
		Com_Printf("Sorry, but your soundcard cannot do memory-mapped I/O\n");
		close(audio_fd);
		return (0);
	}

	if (ioctl(audio_fd, SNDCTL_DSP_GETOSPACE, &info) == -1)
	{
		perror(snddev);
		Com_Printf("Um, cannot do GETOSPACE?\n");
		close(audio_fd);
		return (0);
	}

	shm = &sn;
	shm->splitbuffer = 0;

	/* Set sample bits & speed. */

	if (s = getenv("QUAKE_SOUND_SAMPLEBITS"))
		shm->samplebits = atoi(s);
	else if (tmp = COM_CheckParm("-sndbits"))
		shm->samplebits = atoi(com_argv[tmp + 1]);

	if (shm->samplebits != 16 && shm->samplebits != 8)
	{
		ioctl(audio_fd, SNDCTL_DSP_GETFMTS, &tmp);
		if (tmp & AFMT_S16_LE)
			shm->samplebits = 16;
		else if (tmp & AFMT_U8)
			shm->samplebits = 8;
		else {
			Com_Printf("Could not set sample format\n");
			close(audio_fd);
			return (0);
		}
	}

	if (s = getenv("QUAKE_SOUND_SPEED"))
		shm->speed = atoi(s);
	else if (tmp = COM_CheckParm("-sndspeed"))
		shm->speed = atoi(com_argv[tmp + 1]);
	else
	{
		for (tmp = 0; tmp < sizeof(tryrates) / 4; tmp++)
			if (!ioctl(audio_fd, SNDCTL_DSP_SPEED, &tryrates[tmp]))
				break;
		shm->speed = tryrates[tmp];
	}

	if (s = getenv("QUAKE_SOUND_CHANNELS"))
		shm->channels = atoi(s);
	else if (tmp = COM_CheckParm("-sndmono"))
		shm->channels = 1;
	else shm->channels = 2;

	shm->samples = info.fragstotal * info.fragsize / (shm->samplebits / 8);
	shm->submission_chunk = 1;

	if (shm->channels == 2)
		tmp = 1;
	else
		tmp = 0;

	if (ioctl(audio_fd, SNDCTL_DSP_STEREO, &tmp) < 0)
	{
		perror(snddev);
		Com_Printf("Could not set %s to stereo = %d\n", snddev, shm->channels);
		close(audio_fd);
		return (0);
	}

	Com_Printf("Sound using stereo = %d\n", shm->channels);

	if (tmp)
		shm->channels = 2;
	else
		shm->channels = 1;

	if (ioctl(audio_fd, SNDCTL_DSP_SPEED, &shm->speed) < 0)
	{
		perror(snddev);
		Com_Printf("Could not set %s speed to %d\n", snddev, shm->speed);
		close(audio_fd);
		return (0);
	}

	Com_Printf("Sound on speed = %d\n", shm->speed);

	if (shm->samplebits == 16)
	{
		tmp = AFMT_S16_LE;
		if (ioctl(audio_fd, SNDCTL_DSP_SETFMT, &tmp))
		{
			perror(snddev);
			Com_Printf("Could not support 16-bit data, try 8-bit\n");
			close(audio_fd);
			return (0);
		}
	}
	else if (shm->samplebits == 8)
	{
		tmp = AFMT_U8;
		if (ioctl(audio_fd, SNDCTL_DSP_SETFMT, &tmp))
		{
			perror(snddev);
			Com_Printf("Could not support 8-bit data\n");
			close(audio_fd);
			return (0);
		}
	}
	else {
		perror(snddev);
		Com_Printf("%d-bit sound not supported\n", shm->samplebits);
		close(audio_fd);
		return (0);
	}

	Com_Printf("%s is set to %d-bit format.\n", snddev, shm->samplebits);

	/* Finally, memory map the DMA buffer. */

	shm->buffer = (unsigned char *)mmap(NULL, info.fragstotal
		* info.fragsize,
#ifdef __FreeBSD__
		PROT_READ | PROT_WRITE,
#else
		PROT_WRITE,
#endif
		MAP_FILE | MAP_SHARED, audio_fd, 0);

	if (!shm->buffer || shm->buffer == MAP_FAILED)
	{
		perror(snddev);
		Com_Printf("Could not mmap %s\n", snddev);
		close(audio_fd);
		return (0);
	}

	/* Toggle the trigger & start her up. */

	tmp = 0;
	if (ioctl(audio_fd, SNDCTL_DSP_SETTRIGGER, &tmp) < 0)
	{
		perror(snddev);
		Com_Printf("Could not toggle\n");
		munmap(shm->buffer, shm->samples * shm->samplebits / 8);
		close(audio_fd);
		return (0);
	}

	tmp = PCM_ENABLE_OUTPUT;
	if (ioctl(audio_fd, SNDCTL_DSP_SETTRIGGER, &tmp) < 0)
	{
		perror(snddev);
		Com_Printf("Could not toggle\n");
		close(audio_fd);
		return (0);
	}

	shm->samplepos = 0;
	snd_inited = 1;

	return (1);
}

int
SNDDMA_GetDMAPos(void)
{
	struct count_info count;

	if (!snd_inited)
		return (0);

	if (ioctl(audio_fd, SNDCTL_DSP_GETOPTR, &count) == -1)
	{
		perror(snddev);
		Com_Printf("Uh, sound dead\n");
		close(audio_fd);
		snd_inited = 0;
		return (0);
	}

	/* shm->samplepos = (count.bytes / (shm->samplebits / 8)) & (shm->samples-1);
	fprintf(stderr, "%d    \r", count.ptr); */

	shm->samplepos = count.ptr / (shm->samplebits / 8);

	return (shm->samplepos);
}

void
SNDDMA_Shutdown(void)
{
	if (snd_inited)
	{
		close(audio_fd);
		snd_inited = 0;
	}
}

/*
==============
SNDDMA_Submit

Send sound to device if buffer isn't really the DMA buffer
===============
*/
void
SNDDMA_Submit(void)
{
}
