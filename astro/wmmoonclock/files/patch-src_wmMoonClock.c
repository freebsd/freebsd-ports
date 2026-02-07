--- src/wmMoonClock.c.orig	2017-08-14 22:31:05 UTC
+++ src/wmMoonClock.c
@@ -157,7 +157,8 @@ int main(int argc, char *argv[]) {
     struct tm		*GMTTime, *LocalTime;
     XEvent		event;
     int			i, n, j, ImageNumber, Year, Month, DayOfMonth, digit;
-    long		CurrentLocalTime, CurrentGMTTime, date;
+    time_t		CurrentLocalTime, CurrentGMTTime;
+    long		date;
     double		UT, val, RA, DEC, UTRise, UTSet, LocalHour, hour24();
     int			D, H, M, S, sgn, A, B, q;
     CTrans           	c;
