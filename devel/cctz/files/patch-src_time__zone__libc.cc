--- src/time_zone_libc.cc.orig	2016-04-07 18:26:26 UTC
+++ src/time_zone_libc.cc
@@ -28,7 +28,7 @@
 #  define OFFSET(tm) ((tm).__tm_gmtoff)
 #  define ABBR(tm)   ((tm).__tm_zone)
 # endif
-#elif defined(__APPLE__)
+#elif defined(__APPLE__) || defined(__FreeBSD__)
 # define OFFSET(tm) ((tm).tm_gmtoff)
 # define ABBR(tm)   ((tm).tm_zone)
 #elif defined(__sun)
