--- src/gcompris/log.c.orig	Wed May 12 18:42:15 2004
+++ src/gcompris/log.c	Fri Sep 24 23:34:23 2004
@@ -150,6 +150,7 @@
 void gcompris_log_end (GcomprisBoard *gcomprisBoard, gchar *status) {
   FILE *flog;
   gchar *file;
+  struct tm *tp;
 
   /* Prepare our log */
 
@@ -162,9 +163,7 @@
   time_t end_time = time(NULL);
   double duration = difftime(end_time,start_time);
 
-  struct tm *tp;
-
-  if(gcomprisBoard_set != gcomprisBoard)
+    if(gcomprisBoard_set != gcomprisBoard)
     return;
 
   /* and convert it to UTC or local time representation */
