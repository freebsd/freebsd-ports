--- src/gcompris/log.c.orig	Sun Mar  7 17:36:34 2004
+++ src/gcompris/log.c	Sun Mar  7 17:35:56 2004
@@ -137,6 +137,7 @@
 void gcompris_log_end (GcomprisBoard *gcomprisBoard, gchar *status) {
   FILE *flog;
   gchar *file;
+  struct tm *tp;
 
   /* Prepare our log */
 
@@ -153,7 +154,6 @@
     return;
 
   /* and convert it to UTC or local time representation */
-  struct tm *tp;
   if (USE_UTC)
     tp = gmtime(&start_time);
   else
