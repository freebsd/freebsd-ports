
$FreeBSD$

--- video_x.c.orig	Tue Aug 24 10:46:40 2004
+++ video_x.c	Tue Aug 24 10:46:55 2004
@@ -365,7 +365,7 @@
 	    ui_joypad->data &= ~ui_joypad->button_template->buttons[0];
 	}
 	
-    default:
+    default: break;
     }
 }
 
