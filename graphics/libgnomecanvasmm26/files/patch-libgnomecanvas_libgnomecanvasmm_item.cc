--- libgnomecanvas/libgnomecanvasmm/item.cc.orig	Sat Jun 28 00:33:08 2003
+++ libgnomecanvas/libgnomecanvasmm/item.cc	Sat Jun 28 00:34:20 2003
@@ -45,7 +45,7 @@
 Item::item_construct(Group& group)
 {
   gnome_canvas_item_construct(GNOME_CANVAS_ITEM(gobj()), group.gobj(),
-                              0, 0);
+                              0, (void*)0);
 }
 
 void
