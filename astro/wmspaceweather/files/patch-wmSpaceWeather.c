
$FreeBSD$

--- wmSpaceWeather.c.orig	Sat Aug 17 13:26:47 2002
+++ wmSpaceWeather.c	Sat Aug 17 13:27:10 2002
@@ -115,7 +115,7 @@
 int			i, n, s, k, m, dt1, dt2;
 int 		Year, Month, Day, DayOfMonth, OldDayOfMonth;
 int			Hours, Mins, Secs, OldSecs, xoff, D[10], xsize;
-long		CurrentLocalTime;
+time_t		CurrentLocalTime;
 int			height, UpToDate, LEDOn;
 double		UT, TU, TU2, TU3, T0, gmst, hour24();
 
