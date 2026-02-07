--- gl_vidlinuxglx.c.orig	2020-09-30 11:25:10 UTC
+++ gl_vidlinuxglx.c
@@ -20,7 +20,6 @@ Foundation, Inc., 59 Temple Place - Suite 330, Boston,
 #include <termios.h>
 #include <sys/ioctl.h>
 #include <sys/stat.h>
-#include <sys/vt.h>
 #include <stdarg.h>
 #include <stdio.h>
 #include <signal.h>
@@ -339,8 +338,6 @@ static void HandleEvents(void)
 				{
 					mx += ((int)event.xmotion.x - mwx) * 2;
 					my += ((int)event.xmotion.y - mwy) * 2;
-					mwx = event.xmotion.x;
-					mwy = event.xmotion.y;
 
 					if (mx || my)
 						dowarp = true;
