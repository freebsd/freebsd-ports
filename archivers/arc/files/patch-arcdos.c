--- arcdos.c.orig	2010-08-07 13:06:42 UTC
+++ arcdos.c
@@ -175,14 +175,20 @@ setstamp(f, date, time)		/* set a file's
 	struct tm	tm;
 	struct timeval  tvp[2];
 	int	utimes();
+#if !defined(__FreeBSD__) && !defined(__OpenBSD__)
 	long	tmclock();
+#endif
 	tm.tm_sec = (time & 31) * 2;
 	tm.tm_min = (time >> 5) & 63;
 	tm.tm_hour = (time >> 11);
 	tm.tm_mday = date & 31;
 	tm.tm_mon = ((date >> 5) & 15) - 1;
 	tm.tm_year = (date >> 9) + 80;
+#if !defined(__FreeBSD__) && !defined(__OpenBSD__) && !defined(__NetBSD__)
 	tvp[0].tv_sec = tmclock(&tm);
+#else
+	tvp[0].tv_sec = timelocal(&tm);
+#endif
 	tvp[1].tv_sec = tvp[0].tv_sec;
 	tvp[0].tv_usec = tvp[1].tv_usec = 0;
 	utimes(f, tvp);
