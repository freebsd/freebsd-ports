*** arcdos.c.old	Wed Apr 15 02:58:21 1992
--- arcdos.c	Sat Dec 31 20:32:25 1994
***************
*** 173,186 ****
--- 173,192 ----
  	struct tm	tm;
  	struct timeval  tvp[2];
  	int	utimes();
+ #if !defined(__FreeBSD__) && !defined(__OpenBSD__)
  	long	tmclock();
+ #endif
  	tm.tm_sec = (time & 31) * 2;
  	tm.tm_min = (time >> 5) & 63;
  	tm.tm_hour = (time >> 11);
  	tm.tm_mday = date & 31;
  	tm.tm_mon = ((date >> 5) & 15) - 1;
  	tm.tm_year = (date >> 9) + 80;
+ #if !defined(__FreeBSD__) && !defined(__OpenBSD__) && !defined(__NetBSD__)
  	tvp[0].tv_sec = tmclock(&tm);
+ #else
+ 	tvp[0].tv_sec = timelocal(&tm);
+ #endif
  	tvp[1].tv_sec = tvp[0].tv_sec;
  	tvp[0].tv_usec = tvp[1].tv_usec = 0;
  	utimes(f, tvp);
