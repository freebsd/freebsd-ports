
$FreeBSD$

--- wmMoonClock.c.orig	Thu Aug 15 18:15:26 2002
+++ wmMoonClock.c	Thu Aug 15 18:15:51 2002
@@ -162,7 +162,8 @@
     int			i, n, k, j, ImageNumber;
     int 		Year, Month, DayOfWeek, DayOfMonth;
     int			Hours, Mins, Secs, OldSecs, digit, xoff, xsize;
-    long		CurrentLocalTime, CurrentGMTTime, date;
+    time_t		CurrentLocalTime, CurrentGMTTime;
+    long		date;
     double		UT, val, RA, DEC, UTRise, UTSet, LocalHour, hour24();
     int			D, H, M, S, sgn, A, B, q;
     char		str[10];
