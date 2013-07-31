--- glib/tests/gdatetime.c.orig	2013-03-13 13:39:09.000000000 +0000
+++ glib/tests/gdatetime.c	2013-03-28 10:15:49.000000000 +0000
@@ -1276,7 +1276,7 @@
   gint i1, i2;
 
 #ifdef G_OS_UNIX
-  tz = g_time_zone_new ("Canada/Eastern");
+  tz = g_time_zone_new ("America/Montreal");
 #elif defined G_OS_WIN32
   tz = g_time_zone_new ("Eastern Standard Time");
 #endif
@@ -1309,7 +1309,7 @@
   gint i1, i2;
 
 #ifdef G_OS_UNIX
-  tz = g_time_zone_new ("Canada/Eastern");
+  tz = g_time_zone_new ("America/Montreal");
 #elif defined G_OS_WIN32
   tz = g_time_zone_new ("Eastern Standard Time");
 #endif
