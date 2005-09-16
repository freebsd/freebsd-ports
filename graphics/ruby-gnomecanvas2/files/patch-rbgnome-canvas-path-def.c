--- src/rbgnome-canvas-path-def.c.orig	Sun Jul 31 12:39:54 2005
+++ src/rbgnome-canvas-path-def.c	Fri Sep 16 21:16:00 2005
@@ -82,8 +82,9 @@
     if (NIL_P(obj)) {
         path = gnome_canvas_path_def_new();
     } else if (TYPE(obj) == T_FIXNUM) {
+	gint length;
         path = gnome_canvas_path_def_new_sized(NUM2INT(obj));
-        gint length = NUM2INT(obj);
+        length = NUM2INT(obj);
         if (length > 0) {
             path = gnome_canvas_path_def_new_sized(length);
         } else {
