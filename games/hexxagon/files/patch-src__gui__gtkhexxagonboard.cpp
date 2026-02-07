--- ./src/gui/gtkhexxagonboard.cpp.orig	2010-05-20 18:30:04.000000000 +0400
+++ ./src/gui/gtkhexxagonboard.cpp	2011-06-22 00:38:38.893473851 +0400
@@ -91,11 +91,11 @@
     int cellNo = 0;
     for(int y = 0; y < 9; y++)
     {
-        for(int x = 0; x < 9; x++)
+        for(int x1 = 0; x1 < 9; x1++)
         {
-            if(x - y >= 5)
+            if(x1 - y >= 5)
                 continue;
-            if(y - x >= 5)
+            if(y - x1 >= 5)
                 continue;
 
             if(!bbMask.getBit(cellNo))
@@ -111,8 +111,8 @@
             // Step size
             double xs = w * .748; 
 
-            double posx = round(xs * x);
-            double posy = round(2 * h - (h * x / 2) + h*y);
+            double posx = round(xs * x1);
+            double posy = round(2 * h - (h * x1 / 2) + h*y);
 
             posx -= w * adjust / 2;
             posy -= h * adjust / 2;
@@ -182,11 +182,11 @@
     int cellNo = 0;
     for(int y = 0; y < 9; y++)
     {
-        for(int x = 0; x < 9; x++)
+        for(int x1 = 0; x1 < 9; x1++)
         {
-            if(x - y >= 5)
+            if(x1 - y >= 5)
                 continue;
-            if(y - x >= 5)
+            if(y - x1 >= 5)
                 continue;
            
             // Width and hight
@@ -196,8 +196,8 @@
             // Step size
             double xs = w * .748; 
             
-            double posx = round(xs * x);
-            double posy = round(2 * h - (h * x / 2) + h*y);
+            double posx = round(xs * x1);
+            double posy = round(2 * h - (h * x1 / 2) + h*y);
 
             posx -= w * adjust / 2;
             posy -= h * adjust / 2;
