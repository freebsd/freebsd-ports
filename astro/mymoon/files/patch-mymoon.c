--- mymoon.c.orig	Fri Jul 18 09:25:58 2003
+++ mymoon.c	Fri Jul 18 09:26:35 2003
@@ -122,14 +122,12 @@
 getmaxyx(stdscr,row,cols);
 
 mvprintw(row/4,0,
-"
-        Moon's situation at: %d/%d/%d %d:%d:%d
-        Age: +- %d days
-        Rise: %d/%d/%d %d:%d:%d
-        Set: %d/%d/%d %d:%d:%d
-        Illuminated: %.4f%%
-        Moon->Earth distance: %.3f Km\n\n
-",
+        "Moon's situation at: %d/%d/%d %d:%d:%d\n"
+        "Age: +- %d days\n"
+        "Rise: %d/%d/%d %d:%d:%d\n"
+        "Set: %d/%d/%d %d:%d:%d\n"
+        "Illuminated: %.4f%%\n"
+        "Moon->Earth distance: %.3f Km\n\n",
 date3.days,date3.months,date3.years,date3.hours,date3.minutes,(int)date3.seconds,(int)age,
 date1.days,date1.months,date1.years,date1.hours,date1.minutes,(int)date1.seconds,
 date2.days,date2.months,date2.years,date2.hours,date2.minutes,(int)date2.seconds,light,dist);
