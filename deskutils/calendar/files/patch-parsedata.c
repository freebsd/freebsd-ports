--- parsedata.c.orig	2020-10-18 03:01:26 UTC
+++ parsedata.c
@@ -28,7 +28,7 @@
  */
 
 #include <sys/cdefs.h>
-__FBSDID("$FreeBSD$");
+__FBSDID("$FreeBSD: head/usr.bin/calendar/parsedata.c 367203 2020-10-31 13:32:08Z se $");
 
 #include <ctype.h>
 #include <math.h>
@@ -312,10 +312,7 @@ allfine:
 
 }
 
-void
-remember(int *rememberindex, int *y, int *m, int *d, char **ed, int yy, int mm,
-    int dd, char *extra);
-void
+static void
 remember(int *rememberindex, int *y, int *m, int *d, char **ed, int yy, int mm,
     int dd, char *extra)
 {
