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

# include <X11/Intrinsic.h>

# define NOTITLESTR     "No Title"
# define NODISCSTR      "No Disc"

# define bit(n)			(1 << (n))

/* bits for cdrom_state */
# define CDROM_STATE_PLAY	bit(0)
# define CDROM_STATE_PAUSE	bit(1)
# define CDROM_STATE_STOP	bit(2)
# define CDROM_STATE_EJECTED	bit(3)
# define CDROM_STATE_CYCLE	bit(4)
# define CDROM_STATE_SHUFFLE	bit(5)
# define CDROM_STATE_PROGRAM	bit(6)

/* return codes from cdrom_status() */
# define CDROM_INVALID		1
# define CDROM_PLAYING		2
# define CDROM_PAUSED		3
# define CDROM_COMPLETED	4
# define CDROM_ERROR		5
# define CDROM_NO_STATUS	6

#define	STILL_MOUNTED	1
#define	UNMOUNTED	0
#define CDROM_LEADOUT   0xAA
#define CDROM_MSF       0x02

struct msf {
	unsigned char   minute;
	unsigned char   second;
	unsigned char   frame;
};

struct prognode {
	unsigned char	track;
	Widget		button;
	struct prognode *next;
	struct prognode *prev;
};

typedef struct _cdrom_info {
	unsigned char	curtrack;	/* current track playing	*/
	unsigned char	mintrack;	/* first audio track		*/
	unsigned char	maxtrack;	/* last audio track		*/
	unsigned char	ntracks;	/* size of random track list	*/
	int		duration;	/* seconds played so far	*/
	int		state;		/* state of cd-rom drive	*/
	short		currand;	/* index into random track list */
	short		lastprog;	/* number of selections in prog.*/
	unsigned short	*times;		/* duration of each track	*/
	struct msf 	*addrs;		/* starting minute/second/frames*/
	struct prognode	*selection;	/* currently selected prog. trk	*/
	struct prognode *program;	/* list of programmed tracks	*/
} cdrom_info;

extern int		cdrom_open();
extern void		cdrom_close();
extern int		cdrom_start();
extern int		cdrom_stop();
extern int		cdrom_eject();
extern int		cdrom_pause();
extern int		cdrom_resume();
extern int		cdrom_volume();
extern int		cdrom_get_times();
extern int		cdrom_get_curtrack();
extern int		cdrom_get_msf();
extern int		cdrom_get_curmsf();
extern int		cdrom_play_track();
extern int		cdrom_play_msf();
extern int		cdrom_read_tocentry();
extern int		cdrom_read_tochdr();
extern int		cdrom_status();

extern cdrom_info	cdi;
extern char		*disc_title;
extern char		program_str[];
extern char		*cdInfoDir;

