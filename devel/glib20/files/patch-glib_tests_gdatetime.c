--- glib/tests/gdatetime.c.orig	2012-08-17 00:06:25.000000000 +0000
+++ glib/tests/gdatetime.c	2012-10-23 12:38:55.000000000 +0000
@@ -1230,7 +1230,7 @@
   gint64 u;
   gint i1, i2;
 
-  tz = g_time_zone_new ("Canada/Eastern");
+  tz = g_time_zone_new ("America/Montreal");
   dt = g_date_time_new_utc (2010, 11, 7, 1, 30, 0);
   u = g_date_time_to_unix (dt);
 
@@ -1259,7 +1259,7 @@
   gint64 u, u2;
   gint i1, i2;
 
-  tz = g_time_zone_new ("Canada/Eastern");
+  tz = g_time_zone_new ("America/Montreal");
   dt = g_date_time_new_utc (2010, 11, 7, 1, 30, 0);
   u = g_date_time_to_unix (dt);
   u2 = u;
