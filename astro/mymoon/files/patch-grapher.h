--- grapher.h.orig	2003-07-16 11:24:46 UTC
+++ grapher.h
@@ -13,15 +13,14 @@ memset(&arrow, 0, sizeof(arrow));
 for (z=0;z<=progress;z++) {arrow[z]=bar;}for (k=z;k<=max/4;k++) {arrow[k]=empty;}
 
 mvprintw(row/4,0,  
-"
-        Moon's situation at: %d/%d/%d %d:%d:%d
-        Age: +- %d days
-        Rise: %d/%d/%d %d:%d:%d
-        Set: %d/%d/%d %d:%d:%d
-        Illuminated: %.4f%%  
-        Moon->Earth distance: %.3f Km
-        Distance meter: %s (%d%%)
-",
+        "Moon's situation at: %02d/%02d/%02d %02d:%02d:%02d\n"
+        "Age: +- %d days\n"
+        "Rise: %02d/%02d/%02d %02d:%02d:%02d\n"
+        "Set: %02d/%02d/%02d %02d:%02d:%02d\n"
+        "Illuminated: %.4f%%  \n"
+        "Moon->Earth distance: %.3f Km\n"
+        "Distance meter: %s (%d%%)\n"
+,
 date3.days,date3.months,date3.years,date3.hours,date3.minutes,(int)date3.seconds,(int)age,
 date1.days,date1.months,date1.years,date1.hours,date1.minutes,(int)date1.seconds,
 date2.days,date2.months,date2.years,date2.hours,date2.minutes,(int)date2.seconds,light,distance,arrow,progress*4);
