*** src/splitscreen.c.orig	Fri Nov 12 15:44:12 2004
--- src/splitscreen.c	Fri Nov 12 15:52:19 2004
***************
*** 50,56 ****
  extern struct tln_logline *logtail;
  extern struct tln_logline *temp;
  extern struct tln_logline *viewing;
! extern char spot_ptr[100][82];
  extern char lastmsg[80];
  extern int ptr;

--- 50,56 ----
  extern struct tln_logline *logtail;
  extern struct tln_logline *temp;
  extern struct tln_logline *viewing;
! extern char spot_ptr[MAX_SPOTS][82];
  extern char lastmsg[80];
  extern int ptr;

***************
*** 722,728 ****
  extern SCREEN *packetscreen;
  extern WINDOW *sclwin;
  extern WINDOW *entwin;
! extern char spot_ptr[100][80];
  extern int tncport;
  extern int fdSertnc;
  extern int fdFIFO;
--- 722,728 ----
  extern SCREEN *packetscreen;
  extern WINDOW *sclwin;
  extern WINDOW *entwin;
! extern char spot_ptr[MAX_SPOTS][82];
  extern int tncport;
  extern int fdSertnc;
  extern int fdFIFO;
