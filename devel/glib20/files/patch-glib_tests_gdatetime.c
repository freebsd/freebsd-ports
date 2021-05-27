--- glib/tests/gdatetime.c.orig	2021-05-26 19:32:37.257501000 -0700
+++ glib/tests/gdatetime.c	2021-05-26 19:32:53.078466000 -0700
@@ -2377,7 +2377,7 @@
   gint i1, i2;
 
 #ifdef G_OS_UNIX
-  tz = g_time_zone_new_identifier ("America/Toronto");
+  tz = g_time_zone_new_identifier ("America/Toronto Eastern");
 #elif defined G_OS_WIN32
   tz = g_time_zone_new_identifier ("Eastern Standard Time");
 #endif
@@ -2411,7 +2411,7 @@
   gint i1, i2;
 
 #ifdef G_OS_UNIX
-  tz = g_time_zone_new_identifier ("America/Toronto");
+  tz = g_time_zone_new_identifier ("America/Toronto Eastern");
 #elif defined G_OS_WIN32
   tz = g_time_zone_new_identifier ("Eastern Standard Time");
 #endif
