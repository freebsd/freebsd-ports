--- src/screens.c.orig	Thu Dec 28 11:16:25 2006
+++ src/screens.c	Tue Jan 16 02:53:33 2007
@@ -550,11 +550,14 @@
 
 static boolean insideMenuPosRect(struct MenuPosInfo *rect, int x, int y)
 {
+  int rect_x;
+  int rect_y;
+
   if (rect == NULL)
     return FALSE;
 
-  int rect_x = ALIGNED_XPOS(rect->x, rect->width, rect->align);
-  int rect_y = rect->y;
+  rect_x = ALIGNED_XPOS(rect->x, rect->width, rect->align);
+  rect_y = rect->y;
 
   return (x >= rect_x && x < rect_x + rect->width &&
 	  y >= rect_y && y < rect_y + rect->height);
