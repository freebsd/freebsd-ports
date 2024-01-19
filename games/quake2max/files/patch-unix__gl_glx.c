--- unix/gl_glx.c.orig	2006-01-11 13:04:12 UTC
+++ unix/gl_glx.c
@@ -475,7 +475,6 @@ static void HandleEvents(void)
 	while (XPending(dpy)) {
 
 		XNextEvent(dpy, &event);
-		mx = my = 0;
 		switch(event.type) {
 		case KeyPress:
       		myxtime = event.xkey.time;
@@ -490,15 +489,13 @@ static void HandleEvents(void)
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
