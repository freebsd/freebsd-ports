--- mymoon.c.orig	Wed Jul 16 21:13:55 2003
+++ mymoon.c	Fri Oct 14 19:55:31 2005
@@ -1,4 +1,4 @@
-#include <libnova.h>
+#include <libnova/libnova.h>
 #include <curses.h>
 #include <time.h>
 #include <stdlib.h>
@@ -59,7 +59,7 @@
 memset(&date3, 0, sizeof(date3));
 
 while (1) {
-julian=get_julian_from_sys();
+julian=ln_get_julian_from_sys();
 age=moonphase();
 
 
@@ -67,12 +67,12 @@
 observer.lng=latitude;
 observer.lat=longitude;
 } else {observer.lng=45.12;observer.lat=8.42;}
-light=100*get_lunar_disk(julian);
-dist=get_lunar_earth_dist(julian);
-get_lunar_rst(julian,&observer,&rst);
-get_date(rst.rise,&date1);
-get_date(rst.set,&date2);
-get_date(julian,&date3);
+light=100*ln_get_lunar_disk(julian);
+dist=ln_get_lunar_earth_dist(julian);
+ln_get_lunar_rst(julian,&observer,&rst);
+ln_get_date(rst.rise,&date1);
+ln_get_date(rst.set,&date2);
+ln_get_date(julian,&date3);
 getmaxyx(stdscr,row,cols);
 grapher(dist,row,date1,date2,date3,age,light);
 napms(update * 1000);
