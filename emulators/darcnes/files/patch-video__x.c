--- video_x.c.orig	2000-10-30 22:15:34 UTC
+++ video_x.c
@@ -365,7 +365,7 @@ void handle_joypad_key(int type, KeySym keysym)
 	    ui_joypad->data &= ~ui_joypad->button_template->buttons[0];
 	}
 	
-    default:
+    default: break;
     }
 }
 
