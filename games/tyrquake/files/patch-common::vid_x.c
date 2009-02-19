--- common/vid_x.c.orig	2009-01-24 11:30:23.000000000 +0100
+++ common/vid_x.c	2009-01-24 11:32:14.000000000 +0100
@@ -1059,16 +1059,11 @@
 
 	case MotionNotify:
 	    if (mouse_grab_active) {
-		if (dga_mouse_active) {
-		    mouse_x += x_event.xmotion.x_root;
-		    mouse_y += x_event.xmotion.y_root;
-		} else {
 		    mouse_x = x_event.xmotion.x - (int)(vid.width / 2);
 		    mouse_y = x_event.xmotion.y - (int)(vid.height / 2);
 
 		    if (mouse_x || mouse_y)
 			dowarp = true;
-		}
 	    }
 	    break;
 
