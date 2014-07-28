*** time.c.orig	Sun Mar 15 07:22:29 1992
--- time.c	Sun Jan  3 17:28:45 1999
***************
*** 13,37 ****
   *   returning 0.
   */
  
- #define	TZB
- 
  #ifdef VMS
  #undef TZA
  #undef TZB
  #endif
  
  #include <stdio.h>
  #include <time.h>
  
  #include "astro.h"
  #include "circum.h"
  
  extern char *strncpy();
  #ifndef VMS
  extern long time();
  #endif
  
! static long c0;
  static double mjd0;
  
  /* save current mjd and corresponding system clock for use by inc_mjd().
--- 13,42 ----
   *   returning 0.
   */
  
  #ifdef VMS
  #undef TZA
  #undef TZB
  #endif
  
  #include <stdio.h>
+ #include <string.h>
  #include <time.h>
  
+ #if (defined(__unix__) || defined(unix)) && !defined(USG)
+ #include <sys/param.h>
+ #endif
+ 
  #include "astro.h"
  #include "circum.h"
  
+ #if !(defined(BSD) && BSD >= 199306)
  extern char *strncpy();
  #ifndef VMS
  extern long time();
  #endif
+ #endif
  
! static time_t c0;
  static double mjd0;
  
  /* save current mjd and corresponding system clock for use by inc_mjd().
***************
*** 49,57 ****
  time_fromsys (np)
  Now *np;
  {
  	extern struct tm *gmtime(), *localtime();
  	struct tm *tp;
! 	long c;
  	double day, hr;
  
  	(void) time (&c);
--- 54,64 ----
  time_fromsys (np)
  Now *np;
  {
+ #if !(defined(BSD) && BSD >= 199306)
  	extern struct tm *gmtime(), *localtime();
+ #endif
  	struct tm *tp;
! 	time_t c;
  	double day, hr;
  
  	(void) time (&c);
***************
*** 62,68 ****
--- 69,80 ----
  	    sex_dec (tp->tm_hour, tp->tm_min, tp->tm_sec, &hr);
  	    mjd = day + hr/24.0;
  	    tp = localtime (&c);
+ #ifdef __FreeBSD__
+ 	    tz = -tp->tm_gmtoff/3600;
+ 	    strcpy(tznm, tp->tm_zone);
+ #else
  	    settzstuff (tp->tm_isdst ? 1 : 0, np);
+ #endif
  	} else {
  	    /* if gmtime() doesn't work, we assume the timezone stuff won't
  	     * either, so we just use what it is and leave it alone. Some
***************
*** 114,120 ****
  double inc;
  {
  	if (inc == RTC) {
! 	    long c;
  	    (void) time (&c);
  	    mjd = mjd0 + (c - c0)/SPD;
  	} else
--- 126,132 ----
  double inc;
  {
  	if (inc == RTC) {
! 	    time_t c;
  	    (void) time (&c);
  	    mjd = mjd0 + (c - c0)/SPD;
  	} else
