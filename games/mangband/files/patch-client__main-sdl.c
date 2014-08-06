--- ./client/main-sdl.c.orig	2014-08-05 15:15:31.836673216 +0200
+++ ./client/main-sdl.c	2014-08-05 15:15:31.996665462 +0200
@@ -1031,7 +1031,7 @@
 	//if (td->cx != -1 && td->cy != -1) { 
 	//		RedrawChar(td->cx, td->cy); 
 	//	}
-	if (td->cx == x && td->cy == y) return;
+	if (td->cx == x && td->cy == y) return (0);
 	//if (x == -1 && y == -1) return;
 	if (td->cursor_on) 
 	{
