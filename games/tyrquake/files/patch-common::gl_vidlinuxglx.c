--- common/gl_vidlinuxglx.c.orig	2009-01-24 11:35:16.000000000 +0100
+++ common/gl_vidlinuxglx.c	2009-01-24 11:35:26.000000000 +0100
@@ -387,16 +387,12 @@
 
 	case MotionNotify:
 	    if (mouse_grab_active) {
-		if (dga_mouse_active) {
-		    mouse_x += event.xmotion.x_root;
-		    mouse_y += event.xmotion.y_root;
-		} else {
 		    mouse_x = event.xmotion.x - (int)(vid.width / 2);
 		    mouse_y = event.xmotion.y - (int)(vid.height / 2);
 
 		    if (mouse_x || mouse_y)
 			dowarp = true;
-		}
+
 	    }
 	    break;
 
