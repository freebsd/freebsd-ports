/* $FreeBSD$ */
/*
 * Copyright (C) 1990 Regents of the University of California.
 *
 * Permission to use, copy, modify, distribute, and sell this software and
 * its documentation for any purpose is hereby granted without fee,
 * provided that the above copyright notice appear in all copies and that
 * both that copyright notice and this permission notice appear in
 * supporting documentation, and that the name of the University of
 * California not be used in advertising or publicity pertaining to
 * distribution of the software without specific, written prior
 * permission.  the University of California makes no representations
 * about the suitability of this software for any purpose.  It is provided
 * "as is" without express or implied warranty.
 */

static int c;

# include <stdio.h>
# include <sys/file.h>
# include <sys/types.h>
# include <sys/param.h>
# include <sys/stat.h>
# include <string.h>
# if __FreeBSD_version >= 500003
# include <sys/bio.h>
# endif
# include <sys/buf.h>
# include <sys/time.h>

#include <sys/ioctl.h>
#include <sys/disklabel.h>
#include <sys/cdio.h>

# include "debug.h"
# include "cdrom_freebsd.h"
# include "app.h"

static char     cdrom[] =       "/dev/cd0c";
static char     cdrom1[] =      "/dev/mcd0c";

cdrom_info	cdi;
char		info_filename[256];
FILE		*disc_info = NULL;

static int	cdrom_fd = -1;

extern AppData app_data;

get_stored_info()
{
	int i,n;
	char	line[100];
	char	*title;

	if(disc_info) {
	  fclose(disc_info);
	  disc_info = NULL;
	}

        if ( cdi.maxtrack == 0) {
                return(0);
        }
	for (i = 0, n = 0; i < cdi.maxtrack; i++)
	    n = n + ((i+1) * cdi.times[i]);
	n = n / cdi.maxtrack;

        disc_title = NULL;
	if (app_data.cdInfoDir != NULL)
	    sprintf(info_filename, "%s/cd.%d", app_data.cdInfoDir, n);
	else
	    sprintf(info_filename, "cd.%d", n);

	if ((disc_info = fopen(info_filename, "r")) != NULL)
	{
	    fgets(line, 100, disc_info);
	    title = strchr(line, ':');
	    if (title != NULL)
	    {
	    	*(strchr(title, '\n')) = '\0';
	        disc_title = strdup(title + 1);
	    }
	    fgets(line, 100, disc_info);
	    sscanf(line, "Program: %s", program_str);
	}
	else {
                disc_title = strdup(NOTITLESTR);
		program_str[0] = 0;
	      }
        if (disc_title == NULL) {
                disc_title = strdup(NOTITLESTR);
        }
}

int
cdrom_open() {
	int	n;
	extern void update_title();

	if (cdrom_fd != -1)
		return(cdi.curtrack);

	if (app_data.device != NULL) {
		if ((cdrom_fd = open(app_data.device, O_RDONLY)) == -1) {
			perror(app_data.device);
			return(-1);
		}
	} else {
		if (   (cdrom_fd = open(cdrom, O_RDONLY)) == -1
		    && (cdrom_fd = open(cdrom1, O_RDONLY)) == -1
		   ) {
			perror("open: ");
			return(-1);
		}
	}

	if (cdrom_get_times() == -1) {
		cdrom_close();
		return(-1);
	}

	if ((n = cdrom_get_curtrack()) == -1)
		return(-1);

	get_stored_info();

	update_title();

	if (cdi.state & CDROM_STATE_PLAY)
		cdi.curtrack = n;

	if (cdi.state & CDROM_STATE_SHUFFLE)
		shuffle_setup();

	return(cdi.curtrack);
}

void
cdrom_close() {
	if (cdrom_fd == -1)
		return;

	if (cdi.times != NULL) {
		free((char *) cdi.times);
		free((char *) cdi.addrs);
		cdi.times = NULL;
		cdi.addrs = NULL;
	}

	(void) close(cdrom_fd);
	cdrom_fd = -1;
}


int
cdrom_start() {
	if (cdrom_fd == -1)
		return(-1);

	if (ioctl(cdrom_fd, CDIOCSTART) == -1) {
		perror("ioctl(cdromstart)");
		return(-1);
	}

	return(0);
}

int
cdrom_stop() {
	if (cdrom_fd == -1)
		return(-1);

	if (ioctl(cdrom_fd, CDIOCSTOP) == -1) {
		perror("ioctl(cdromstop)");
		return(-1);
	}

	return(0);
}

int
cdrom_eject() {
	if (cdrom_fd == -1)
		return(-1);

        if (ioctl(cdrom_fd, CDIOCALLOW) == -1) {
		perror("ioctl(cdromallow)");
		return(-1);
	} 

	if (ioctl(cdrom_fd, CDIOCEJECT) == -1) {
		perror("ioctl(cdromeject)");
		return(-1);
	}

	return(0);
}

int
cdrom_pause() {
	if (cdrom_fd == -1)
		return(-1);

	if (ioctl(cdrom_fd, CDIOCPAUSE) == -1) {
		perror("ioctl(cdrompause)");
		return(-1);
	}

	return(0);
}

int
cdrom_resume() {
	if (cdrom_fd == -1)
		return(-1);

	if (ioctl(cdrom_fd, CDIOCRESUME) == -1) {
		perror("ioctl(cdromresume)");
		return(-1);
	}

	return(0);
}

int
cdrom_volume(left_vol, right_vol)
	int			left_vol;
	int			right_vol;
{
	struct ioc_vol	vol;

	if (cdrom_fd == -1)
		return(-1);

	vol.vol[0] = left_vol;
	vol.vol[1] = right_vol;
	vol.vol[2] = 0;
	vol.vol[3] = 0;

	if (ioctl(cdrom_fd, CDIOCSETVOL, &vol) == -1) {
		perror("ioctl(cdromvolctrl)");
		return(-1);
	}

	return(0);
}

int
cdrom_get_times() {
	struct ioc_toc_header	tochdr;
	extern unsigned short	*ushort_malloc();
	extern struct msf	*msf_malloc();
	unsigned long		trk, trk_total, otime;
	struct msf		msf;

	if (cdrom_read_tochdr(&tochdr) == -1)
		return(-1);

	cdi.mintrack = tochdr.starting_track;
	cdi.maxtrack = tochdr.ending_track;

	if (cdi.times != NULL)
	{
		free((char *) cdi.times);
		free((char *) cdi.addrs);
		cdi.times = NULL;
		cdi.addrs = NULL;
	}

	cdi.times = ushort_malloc(cdi.maxtrack - cdi.mintrack + 1);
	cdi.addrs = msf_malloc(cdi.maxtrack - cdi.mintrack + 2);

	otime = 0;

	for (trk = cdi.mintrack; trk <= cdi.maxtrack; trk++) {
		if (cdrom_get_msf(trk, &msf, &trk_total) == -1)
			return(-1);

		/* record start address for each track (track 1 starts at 0)*/
		cdi.addrs[trk - cdi.mintrack] = msf;

		trk_total -= otime;

		/* use start time of next track as length of previous */
		if (otime != 0) 
		{
			cdi.times[trk - cdi.mintrack - 1] = trk_total;
		}

		otime += trk_total;

	}

        /* find start of  leadout to get length of last track */
        if (cdrom_get_msf(CDROM_LEADOUT, &msf, &trk_total) == -1)
                return(-1);

        /* recode leadout start address */
        cdi.addrs[trk - cdi.mintrack] = msf;
        trk_total -= otime;
        otime += trk_total;

        cdi.times[trk - cdi.mintrack - 1] = trk_total;
	return(0);
}

int
cdrom_get_curtrack() {
	struct cd_sub_channel_info data;

	if (cdrom_read_subchannel(&data) == -1)
	  return(-1);

	switch (data.header.audio_status) {
		case CD_AS_AUDIO_INVALID:
		return(-1);

		/* playing track subchnl.cdsc_trk */
	      case CD_AS_PLAY_IN_PROGRESS:
		return((int) data.what.position.track_number);

		/* paused on track subchnl.cdsc_trk */
	      case CD_AS_PLAY_PAUSED:
		return((int) data.what.position.track_number);

		/* punt */
	      case CD_AS_PLAY_COMPLETED:
		return(0);

	      case CD_AS_PLAY_ERROR:
		return(-1);

		/* punt */
	      case CD_AS_NO_STATUS:
		debug_printf(1, "cdrom_get_curtrack: no status\n");
		return(0);
	}

	/* bad value in cdsc_audiostatus */
	return(-1);
}

int
cdrom_get_msf(track, msf, length)
	unsigned long		track;
	struct msf		*msf;
	unsigned long		*length;
{
        struct cd_toc_entry     data;
	
	if (cdrom_read_tocentry(track, &data, sizeof(data)) == -1)
	  return(-1);

	msf->minute = data.addr.msf.minute;
	msf->second = data.addr.msf.second;
	msf->frame =  data.addr.msf.frame;
	*length = (((unsigned int) msf->minute) * 60) + (unsigned int) msf->second;
	return(0);
}

int
cdrom_get_curmsf(msf)
	struct msf *msf;
{
	struct cd_sub_channel_info data;

	if (cdrom_read_subchannel(&data) == -1)
	  return(-1);

	msf->minute = data.what.position.absaddr.msf.minute;
	msf->second = data.what.position.absaddr.msf.second;
	msf->frame =  data.what.position.absaddr.msf.frame;
	return (0);
}

int
cdrom_play_track(start_track, end_track)
	unsigned char		start_track;
	unsigned char		end_track;
{
	struct	ioc_play_track	ti;
	struct	ioc_play_msf	play_addr;
	char *addr;

	if (cdrom_fd == -1)
		return(-1);

	play_addr.start_m = cdi.addrs[start_track - cdi.mintrack].minute;
	play_addr.start_s = cdi.addrs[start_track - cdi.mintrack].second;
	play_addr.start_f = cdi.addrs[start_track - cdi.mintrack].frame;
	play_addr.end_m = cdi.addrs[end_track - cdi.mintrack + 1].minute;
	play_addr.end_s = cdi.addrs[end_track - cdi.mintrack + 1].second;
	play_addr.end_f = cdi.addrs[end_track - cdi.mintrack + 1].frame - 1;

	if(play_addr.end_f >= 75) {
	  play_addr.end_f = 74;
	  play_addr.end_s--;
	}
	if(play_addr.end_s >= 60) {
	  play_addr.end_s = 59;
	  play_addr.end_m--;
	}
	addr = (char *)&play_addr;
	if (ioctl(cdrom_fd, CDIOCPLAYMSF, &play_addr) == -1) {
		perror("ioctl(cdromplaymsftrk)");
		return(-1);
	}

	return(0);
}

int
cdrom_play_msf(start_msf, end_msf)
	struct msf	*start_msf;
	struct msf	*end_msf;
{
	struct	ioc_play_msf	play_addr;

	if (cdrom_fd == -1)
		return(-1);

	play_addr.start_m = start_msf->minute;
	play_addr.start_s = start_msf->second;
	play_addr.start_f = start_msf->frame;
	play_addr.end_m = end_msf->minute;
	play_addr.end_s = end_msf->second;
	play_addr.end_f = end_msf->frame;

	if (ioctl(cdrom_fd, CDIOCPLAYMSF, &play_addr) == -1) {
		perror("ioctl(cdromplaymsf)");
		return(-1);
	}

	return(0);
}


int
cdrom_read_subchannel(data)
	struct cd_sub_channel_info *data;
{
	struct ioc_read_subchannel	subchnl;

	if (cdrom_fd == -1)
		return(-1);

        subchnl.address_format = CD_MSF_FORMAT;
	subchnl.data_format = CD_CURRENT_POSITION;
	subchnl.data_len = /* sizeof(struct cd_sub_channel_info)*/ 16;
	subchnl.track = 0;
	subchnl.data = data;

	if (ioctl(cdrom_fd, CDIOCREADSUBCHANNEL, (char *) &subchnl) == -1) {
		fprintf(stderr, "ioctl(cdromsubchnl): ");
		perror(cdrom);
		return(-1);
	}

	return(0);
}

int
cdrom_read_track(track, data)
	unsigned int		track;
	struct cd_sub_channel_info *data;
{
	struct ioc_read_subchannel	subchnl;

	if (cdrom_fd == -1)
		return(-1);

	subchnl.address_format = CD_MSF_FORMAT;
	subchnl.data_format = CD_TRACK_INFO;
	subchnl.data_len = /* sizeof(struct cd_sub_channel_info)*/ 24;
	subchnl.track = track;
	subchnl.data = data;

	if (ioctl(cdrom_fd, CDIOCREADSUBCHANNEL, (char *) &subchnl) == -1) {
		fprintf(stderr, "ioctl(cdromsubchnltrk): ");
		perror(cdrom);
		return(-1);
	}

	return(0);
}

int
cdrom_read_tocentry(track, data, size)
	unsigned int		track;
        struct cd_toc_entry *data;
     int size;
{
	struct ioc_read_toc_entry tocentry;

	if (cdrom_fd == -1)
		return(-1);

	tocentry.starting_track = (unsigned char)track;
	tocentry.address_format = CD_MSF_FORMAT;
	tocentry.data_len = /* sizeof(struct cd_toc_entry)*/ size;
	tocentry.data = data;

	if (ioctl(cdrom_fd, CDIOREADTOCENTRYS, (char *) &tocentry) == -1) {
		perror("ioctl(cdromreadtocentry)");
		return(-1);
	}

	return(0);
}

int
cdrom_read_tochdr(tochdr)
	struct ioc_toc_header	*tochdr;
{
	if (cdrom_fd == -1)
		return(-1);

	if (ioctl(cdrom_fd, CDIOREADTOCHEADER, (char *) tochdr) == -1) {
		perror("ioctl(cdromreadtochdr): ");
		return(-1);
	}

	return(0);
}

int
cdrom_status() {
	struct cd_sub_channel_info data;

	if (cdrom_read_subchannel(&data) == -1)
	  return(-1);

	switch (data.header.audio_status) {
		case CD_AS_AUDIO_INVALID:
		return(CDROM_INVALID);

		case CD_AS_PLAY_IN_PROGRESS:
		return(CDROM_PLAYING);

		case CD_AS_PLAY_PAUSED:
		return(CDROM_PAUSED);

		case CD_AS_PLAY_COMPLETED:
		return(CDROM_COMPLETED);

		case CD_AS_PLAY_ERROR:
		return(CDROM_ERROR);

		case CD_AS_NO_STATUS:
		return(CDROM_NO_STATUS);
	}

	return(-1);
}

unsigned short *
ushort_malloc(n)
	int		n;
{
	extern char	*calloc();
	unsigned short	*ptr;

	ptr = (unsigned short *) calloc(n, sizeof(unsigned short));
	if (ptr == NULL) {
		perror("calloc");
		exit(1);
	}

	return(ptr);
}

struct msf *
msf_malloc(n)
	int		n;
{
	extern char	*calloc();
	struct msf	*ptr;

	ptr = (struct msf *) calloc(n, sizeof(struct msf));
	if (ptr == NULL) {
		perror("calloc");
		exit(1);
	}

	return(ptr);
}

int
cdrom_disp_cdi() {
	int trk;

	fprintf(stderr,"CDI structure:\n");
	fprintf(stderr,"\tcurtrack: %d\n",cdi.curtrack);
	fprintf(stderr,"\tmin: %d  max: %d  total: %d\n",
		cdi.mintrack, cdi.maxtrack, cdi.ntracks);
	fprintf(stderr,"\tdur: %d  state: %2x\n",cdi.duration, cdi.state);
	fprintf(stderr,"\tcurrand: %d  lastprog: %d\n",
		cdi.currand, cdi.lastprog);
	fprintf(stderr,"\n\tTracklist:\n");
	if (cdi.maxtrack != cdi.mintrack) {
		for (trk=0; trk<=cdi.maxtrack-cdi.mintrack+1; trk++) {
			fprintf(stderr,"\t%3d: %d %02d:%02d %d\n",trk,cdi.times[trk],
				cdi.addrs[trk].minute,cdi.addrs[trk].second,
				cdi.addrs[trk].frame);
		}
	}
}
