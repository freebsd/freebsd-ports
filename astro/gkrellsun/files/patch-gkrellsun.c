
$FreeBSD$

--- gkrellsun.c.orig	Thu Aug 15 15:32:05 2002
+++ gkrellsun.c	Thu Aug 15 15:35:13 2002
@@ -92,8 +92,9 @@
 static void update_sun_data(Sun * sun)
 {
     struct tm *time_struc;	/* The tm struct is defined in <time.h> */
+    time_t current_gmt;
     gdouble local_std_time, univ_time, eot;
-    glong current_gmt, date;
+    glong date;
     gint day_of_month, month, year;
 
     current_gmt = time(CurrentTime);	/* CurrentTime defined in <X11/X.h> */
