--- ./linux/gl_glx.c.orig	Tue May 16 15:20:09 2006
+++ ./linux/gl_glx.c	Tue May 16 15:20:10 2006
@@ -34,7 +34,9 @@
 #include <termios.h>
 #include <sys/ioctl.h>
 #include <sys/stat.h>
+#ifdef __linux__
 #include <sys/vt.h>
+#endif
 #include <stdarg.h>
 #include <stdio.h>
 #include <unistd.h>
@@ -342,10 +344,8 @@
 				} 
 				else 
 				{
-					mx = -((int)event.xmotion.x - mwx);// * 2;
-					my = -((int)event.xmotion.y - mwy);// * 2;
-					mwx = event.xmotion.x;
-					mwy = event.xmotion.y;
+					mx += ((int)event.xmotion.x - mwx) * 2;
+					my += ((int)event.xmotion.y - mwy) * 2;
 
 					if (mx || my)
 						dowarp = true;
