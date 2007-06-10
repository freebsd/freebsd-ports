--- e_placelib.c.orig	Tue Jul 26 09:39:59 2005
+++ e_placelib.c
@@ -162,7 +162,7 @@
 void
 sel_place_lib_obj(void)
 {
-    canvas_kbd_proc = transform_lib_obj;
+    canvas_kbd_proc = (void (*)())transform_lib_obj;
     canvas_locmove_proc = null_proc;
     canvas_ref_proc = null_proc;
     canvas_leftbut_proc = null_proc;
