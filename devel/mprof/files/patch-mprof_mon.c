*** ../m/mprof_mon.c	Tue Apr 20 13:36:09 1993
--- mprof_mon.c	Fri Sep 17 17:09:01 1993
***************
*** 5,10 ****
--- 5,11 ----
   */
  
  #include	<stdio.h>
+ #include	<unistd.h>
  #include	<sys/file.h>
  #include	"mprof.h"
  
***************
*** 411,417 ****
  #ifdef sun
      on_exit(mprof_exit, NULL);
  #endif
! #ifdef mips
      atexit(mprof_exit);
  #endif    
      
--- 412,418 ----
  #ifdef sun
      on_exit(mprof_exit, NULL);
  #endif
! #if defined(mips) || defined(__FreeBSD__)
      atexit(mprof_exit);
  #endif    
      
