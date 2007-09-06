--- ./code/unix/linux_glimp.c.orig	Sun Apr 30 11:32:56 2006
+++ ./code/unix/linux_glimp.c	Sun Jun 11 17:26:26 2006
@@ -631,8 +631,14 @@
 
           dx = ((int)event.xmotion.x - mwx);
           dy = ((int)event.xmotion.y - mwy);
-					mx += dx;
-					my += dy;
+          if (abs(dx) > 1)
+            mx += dx * 2;
+          else
+            mx += dx;
+          if (abs(dy) > 1)
+            my += dy * 2;
+          else
+            my += dy;
 
           mwx = event.xmotion.x;
           mwy = event.xmotion.y;
