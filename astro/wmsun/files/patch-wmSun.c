
$FreeBSD$

--- wmSun.c.orig	Thu Aug 15 18:04:04 2002
+++ wmSun.c	Thu Aug 15 18:06:24 2002
@@ -129,7 +129,8 @@
     int 		Year, Month, DayOfWeek, OldLocalDayOfMonth;
     int			LocalDayOfMonth,	DayOfMonth;
     int			Hours, Mins, Secs, OldSecs, digit, xoff, xsize;
-    long		CurrentLocalTime, CurrentGMTTime, date;
+    time_t		CurrentLocalTime, CurrentGMTTime;
+    long		date;
     double		UT, val, RA, DEC, LTRise, LTSet, LocalHour, hour24();
     int			D, H, M, S, sgn, A, B, q;
     char		str[10];
