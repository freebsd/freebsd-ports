--- wmSun.c.orig	2015-04-01 21:07:58 UTC
+++ wmSun.c
@@ -76,7 +76,8 @@ int main(int argc, char *argv[]) {
     int			LocalDayOfMonth, DayOfMonth;
     int			Hours, Mins, Secs, OldSecs, digit, xoff, xsize;
     int			OldMins;
-    long		CurrentLocalTime, CurrentGMTTime, date;
+    time_t		CurrentLocalTime, CurrentGMTTime;
+    long		date;
     double		UT, val, RA, DEC, LTRise, LTSet, LocalHour, hour24();
     int			D, H, M, S, sgn, A, B, q;
     char		str[10];
