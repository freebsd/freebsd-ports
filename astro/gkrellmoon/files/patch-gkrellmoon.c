
$FreeBSD$

--- gkrellmoon.c.orig	Thu Aug 15 20:40:11 2002
+++ gkrellmoon.c	Thu Aug 15 20:41:50 2002
@@ -55,8 +55,9 @@
 update_moon_data(Moon * moon)
 {
     struct tm *time_struc;	/* The tm struct is defined in <time.h> */
+    time_t current_gmt;
     gdouble local_std_time, univ_time, eot;
-    glong current_gmt, date;
+    glong date;
     gint day_of_month, month, year;
 
     current_gmt = time(CurrentTime);	/* CurrentTime defined in <X11/X.h> */
