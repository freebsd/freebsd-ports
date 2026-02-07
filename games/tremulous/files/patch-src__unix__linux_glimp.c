--- ./tremulous-1.1.0-src/src/unix/linux_glimp.c.orig	Fri Mar  3 20:59:01 2006
+++ ./tremulous-1.1.0-src/src/unix/linux_glimp.c	Wed Jun  7 16:57:12 2006
@@ -619,8 +619,15 @@
 
           dx = ((int)event.xmotion.x - mwx);
           dy = ((int)event.xmotion.y - mwy);
-					mx += dx;
-					my += dy;
+
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
