*** score.c.orig	Thu Jan 22 09:58:52 1998
--- score.c	Sun Apr 12 14:00:32 1998
***************
*** 56,61 ****
--- 56,62 ----
  
  #include <X11/Xos.h>	/* brings in <sys/file.h> */
  #include <stdio.h>
+ #include <stdlib.h>
  #include "xrobots.h"
  
  /*----------------------------------------------------------------------*/
***************
*** 67,73 ****
  
  static SCORE scores[MAXSCORES];
  
! void 	show_scores(),   
  	write_out_scores();
  	
  static void new_high_score(),
--- 68,74 ----
  
  static SCORE scores[MAXSCORES];
  
! static void 	show_scores(),   
  	write_out_scores();
  	
  static void new_high_score(),
***************
*** 110,121 ****
  #ifndef SYSV
    flock(scorefile->_file, LOCK_EX);
  #endif
!   while( fgets(scores[i].score,6,scorefile) 	/* get score */
!       && fgets(scores[i].name,26,scorefile) 	/* get name */
!       && fgetc(scorefile))			/* and newline */
!   {
!     i++;
!     if( i > MAXSCORES ) break;
    }
  }
  
--- 111,123 ----
  #ifndef SYSV
    flock(scorefile->_file, LOCK_EX);
  #endif
!   for(i = 0; i < MAXSCORES; i++) {
!     if(!fgets(scores[i].score, 6, scorefile)) 	/* get score */
!       break;
!     if(!fgets(scores[i].name, 26, scorefile)) 	/* get name */
!       break;
!     if(!fgetc(scorefile))			/* and newline */
!       break;
    }
  }
  
***************
*** 194,200 ****
  
  
  /*ARGSUSED*/
! static XtCallbackProc 
  popdown_callback(w, closure, call_data)
    Widget w;
    caddr_t closure;
--- 196,202 ----
  
  
  /*ARGSUSED*/
! static void
  popdown_callback(w, closure, call_data)
    Widget w;
    caddr_t closure;
***************
*** 253,259 ****
  show_scores()
  {
    int i;
!   char tmp_str[31];
    Arg tmp_arg;
  
    for(i = 0;i<MAXSCORES;i++) {
--- 255,261 ----
  show_scores()
  {
    int i;
!   char tmp_str[64];
    Arg tmp_arg;
  
    for(i = 0;i<MAXSCORES;i++) {
