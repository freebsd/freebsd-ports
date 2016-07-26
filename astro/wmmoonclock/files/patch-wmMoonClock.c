--- wmMoonClock.c.orig	1999-06-07 14:27:18 UTC
+++ wmMoonClock.c
@@ -162,7 +162,8 @@ int main(int argc, char *argv[]) {
     int			i, n, k, j, ImageNumber;
     int 		Year, Month, DayOfWeek, DayOfMonth;
     int			Hours, Mins, Secs, OldSecs, digit, xoff, xsize;
-    long		CurrentLocalTime, CurrentGMTTime, date;
+    time_t		CurrentLocalTime, CurrentGMTTime;
+    long		date;
     double		UT, val, RA, DEC, UTRise, UTSet, LocalHour, hour24();
     int			D, H, M, S, sgn, A, B, q;
     char		str[10];
