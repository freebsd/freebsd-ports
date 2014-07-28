*** bin/trans.h.bak	Thu May  1 03:12:00 1997
--- bin/trans.h	Mon May  5 19:35:52 1997
***************
*** 81,87 ****
  /*
  	if you want to use non-ANSI utime (), uncomment the following line
  */
! /* #define	USE_UTIMBUF */
  
  /*
  	if your compiler doesn't define utimbuf, ...
--- 81,89 ----
  /*
  	if you want to use non-ANSI utime (), uncomment the following line
  */
! #ifdef __FreeBSD__
! #define      USE_UTIMBUF
! #endif
  
  /*
  	if your compiler doesn't define utimbuf, ...
