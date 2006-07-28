--- ./unix/gl_glx.c.orig	Wed Jan  4 08:01:06 2006
+++ ./unix/gl_glx.c	Fri Jul 28 13:33:32 2006
@@ -476,7 +476,6 @@
 	while (XPending(dpy)) {
 
 		XNextEvent(dpy, &event);
-		mx = my = 0;
 		switch(event.type) {
 		case KeyPress:
       		myxtime = event.xkey.time;
@@ -498,8 +497,6 @@
 				{
 					mx += ((int)event.xmotion.x - mwx) * 2;
 					my += ((int)event.xmotion.y - mwy) * 2;
-					mwx = event.xmotion.x;
-					mwy = event.xmotion.y;
 
 					if (mx || my)
 						dowarp = true;
