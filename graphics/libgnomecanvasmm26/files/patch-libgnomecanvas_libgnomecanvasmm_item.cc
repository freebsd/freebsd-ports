--- libgnomecanvas/libgnomecanvasmm/item.cc.orig	Wed Jul  9 17:36:39 2003
+++ libgnomecanvas/libgnomecanvasmm/item.cc	Wed Jul  9 17:44:53 2003
@@ -44,8 +44,9 @@
 void
 Item::item_construct(Group& group)
 {
+  va_list ap;
   gnome_canvas_item_construct(GNOME_CANVAS_ITEM(gobj()), group.gobj(),
-                              0, 0);
+                              0, ap);
 }
 
 void
