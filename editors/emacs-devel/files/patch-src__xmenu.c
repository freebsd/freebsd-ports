--- src/xmenu.c.orig	Sun Sep  3 01:35:27 2006
+++ src/xmenu.c	Sun Sep  3 01:37:02 2006
@@ -1391,9 +1391,10 @@
      Lisp_Object frame;
 {
   GtkWidget *menubar;
-  BLOCK_INPUT;
-  FRAME_PTR f = check_x_frame (frame);
+  FRAME_PTR f;
 
+  BLOCK_INPUT;
+  f = check_x_frame (frame);
   if (FRAME_EXTERNAL_MENU_BAR (f))
     set_frame_menubar (f, 0, 1);
 
