--- linux/in_x11.c.orig	Thu Jun 29 12:26:46 2006
+++ linux/in_x11.c	Thu Jun 29 11:55:06 2006
@@ -589,10 +589,8 @@
 					}
 					else
 					{
-						mx = -((int)event.xmotion.x - mwx);// * 2;
-						my = -((int)event.xmotion.y - mwy);// * 2;
-						mwx = event.xmotion.x;
-						mwy = event.xmotion.y;
+						mx += ((int)event.xmotion.x - mwx);
+						my += ((int)event.xmotion.y - mwy);
 
 						if (mx || my)
 							dowarp = qtrue;
