diff -urN ../o2em117src.old/src/vdc.c ./src/vdc.c
--- ../o2em117src.old/src/vdc.c	Fri Jun 24 16:02:21 2005
+++ ./src/vdc.c	Fri Jun 24 16:00:34 2005
@@ -339,8 +339,7 @@
 			last=t;
 		}
 		if (curr) {
-			text_mode(0);
-			textprintf(bmp, font, 20 , 4, 7, "FPS: %3d",(int)((200.0*TICKSPERSEC)/curr+0.5));
+			textprintf_ex(bmp, font, 20, 4, 7, 0, "FPS: %3d",(int)((200.0*TICKSPERSEC)/curr+0.5));
 		}
 	}
 
@@ -528,9 +527,8 @@
 
 
 static void txtmsg(int x, int y, int c, const char *s){
-	text_mode(-1);
-	textout_centre(bmp, font, s, x+1 , y+1, 32);
-	textout_centre(bmp, font, s, x , y, c);
+	textout_centre_ex(bmp, font, s, x+1 , y+1, 32, -1);
+	textout_centre_ex(bmp, font, s, x , y, c, -1);
 }
 
 
@@ -604,7 +602,6 @@
 		init_keyboard();
 	}
 
-	set_window_close_button(TRUE);
-	set_window_close_hook(window_close_hook);
+	set_close_button_callback(window_close_hook);
 
 }
