--- glib/tests/gdatetime.c.orig	2014-03-09 10:29:13.925231275 +0000
+++ glib/tests/gdatetime.c	2014-03-09 10:30:18.235227107 +0000
@@ -1322,7 +1322,7 @@
   gint i1, i2;
 
 #ifdef G_OS_UNIX
-  tz = g_time_zone_new ("America/Toronto");
+  tz = g_time_zone_new ("America/Toronto Eastern");
 #elif defined G_OS_WIN32
   tz = g_time_zone_new ("Eastern Standard Time");
 #endif
@@ -1355,7 +1355,7 @@
   gint i1, i2;
 
 #ifdef G_OS_UNIX
-  tz = g_time_zone_new ("America/Toronto");
+  tz = g_time_zone_new ("America/Toronto Eastern");
 #elif defined G_OS_WIN32
   tz = g_time_zone_new ("Eastern Standard Time");
 #endif
