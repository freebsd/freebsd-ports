--- ./gl_vidlinuxglx.c.orig	Sat Jun 10 12:08:13 2006
+++ ./gl_vidlinuxglx.c	Sat Jun 10 12:08:13 2006
@@ -20,7 +20,6 @@
 #include <termios.h>
 #include <sys/ioctl.h>
 #include <sys/stat.h>
-#include <sys/vt.h>
 #include <stdarg.h>
 #include <stdio.h>
 #include <signal.h>
@@ -339,8 +338,6 @@
 				{
 					mx += ((int)event.xmotion.x - mwx) * 2;
 					my += ((int)event.xmotion.y - mwy) * 2;
-					mwx = event.xmotion.x;
-					mwy = event.xmotion.y;
 
 					if (mx || my)
 						dowarp = true;
