--- client/main-sdl.c.orig	2014-02-04 19:51:35.412181886 +0100
+++ client/main-sdl.c	2014-02-04 19:51:50.859119136 +0100
@@ -1031,7 +1031,7 @@
 	//if (td->cx != -1 && td->cy != -1) { 
 	//		RedrawChar(td->cx, td->cy); 
 	//	}
-	if (td->cx == x && td->cy == y) return;
+	if (td->cx == x && td->cy == y) return (0);
 	//if (x == -1 && y == -1) return;
 	if (td->cursor_on) 
 	{
