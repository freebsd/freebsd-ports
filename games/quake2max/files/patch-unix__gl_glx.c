--- unix/gl_glx.c.orig	Wed Jan 11 10:04:12 2006
+++ unix/gl_glx.c	Sat Dec 30 18:21:42 2006
@@ -475,7 +475,6 @@
 	while (XPending(dpy)) {
 
 		XNextEvent(dpy, &event);
-		mx = my = 0;
 		switch(event.type) {
 		case KeyPress:
       		myxtime = event.xkey.time;
@@ -490,15 +489,13 @@
 		case MotionNotify:
 			if (mouse_active) {
 				if (dgamouse) {
-					mx += (event.xmotion.x + win_x) * 2;
-					my += (event.xmotion.y + win_y) * 2;
+					mx += (event.xmotion.x + win_x);
+					my += (event.xmotion.y + win_y);
 				} 
 				else 
 				{
-					mx += ((int)event.xmotion.x - mwx) * 2;
-					my += ((int)event.xmotion.y - mwy) * 2;
-					mwx = event.xmotion.x;
-					mwy = event.xmotion.y;
+					mx += ((int)event.xmotion.x - mwx);
+					my += ((int)event.xmotion.y - mwy);
 
 					if (mx || my)
 						dowarp = true;
