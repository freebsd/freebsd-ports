--- d_picobj.c.orig	Tue Jul 26 09:39:58 2005
+++ d_picobj.c
@@ -127,7 +127,7 @@
     /* draw it and anything on top of it */
     redisplay_line(box);
     put_msg("Please enter name of Picture Object file in EDIT window");
-    edit_item((char *) box, O_POLYLINE, 0, 0);
+    edit_item(box, O_POLYLINE, 0, 0);
     picobj_drawing_selected();
     draw_mousefun_canvas();
 }
