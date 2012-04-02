
$FreeBSD$

--- libmuine/rb-cell-renderer-pixbuf.c.orig
+++ libmuine/rb-cell-renderer-pixbuf.c
@@ -295,14 +295,14 @@
 
   if ((flags & GTK_CELL_RENDERER_SELECTED) == GTK_CELL_RENDERER_SELECTED)
     {
-      if (GTK_WIDGET_HAS_FOCUS (widget))
+      if (gtk_widget_has_focus (widget))
         state = GTK_STATE_SELECTED;
       else
         state = GTK_STATE_ACTIVE;
     }
   else
     {
-      if (GTK_WIDGET_STATE (widget) == GTK_STATE_INSENSITIVE)
+      if (GTK_OBJECT_FLAGS (widget) == GTK_STATE_INSENSITIVE)
         state = GTK_STATE_INSENSITIVE;
       else
         state = GTK_STATE_NORMAL;
