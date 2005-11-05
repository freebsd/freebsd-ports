--- src/rbgnome-canvas-path-def.c.orig	Sun Oct 16 20:51:48 2005
+++ src/rbgnome-canvas-path-def.c	Sun Oct 16 20:53:08 2005
@@ -72,7 +72,8 @@
     if (NIL_P(obj)) {
         path = gnome_canvas_path_def_new();
     } else if (TYPE(obj) == T_FIXNUM) {
-        gint length = NUM2INT(obj);
+        gint length;
+        length = NUM2INT(obj);
         if (length > 0) {
             path = gnome_canvas_path_def_new_sized(length);
         } else {
