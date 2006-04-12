--- src/gl_glx.c.orig	Sun Mar 14 23:25:43 2004
+++ src/gl_glx.c	Wed Feb 22 20:20:51 2006
@@ -797,8 +797,6 @@
 				{
 					mx += ((int)event.xmotion.x - mwx) * 2;
 					my += ((int)event.xmotion.y - mwy) * 2;
-					mwx = event.xmotion.x;
-					mwy = event.xmotion.y;
 
 					if (mx || my)
 						dowarp = true;
