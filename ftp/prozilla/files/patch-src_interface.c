--- src/interface.c.orig	Thu Nov  3 23:18:15 2005
+++ src/interface.c	Fri Nov 25 12:54:48 2005
@@ -281,6 +281,7 @@
   char buf[1000];
   int i = 0;
   int line = 1;
+  int secs_left;
   
   //  erase();
     refresh();
@@ -338,7 +339,6 @@
 	   current_dl_speed , proz_download_get_average_speed(download) / 1024);
     mvprintw(line++,1, buf);
     clrtoeol();
-    int secs_left;
 
     if ((secs_left = proz_download_get_est_time_left(download)) != -1)
     {
