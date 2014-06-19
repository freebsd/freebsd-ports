diff --git a/gnomemusic/widgets.py b/gnomemusic/widgets.py
index ee5835d..81c48c3 100644
--- gnomemusic/widgets.py
+++ gnomemusic/widgets.py
@@ -140,11 +140,13 @@ class AlbumWidget(Gtk.EventBox):
         )
         self.view.set_view_type(Gd.MainViewType.LIST)
         self.album = None
+        self.header_bar = None
         self.view.connect('item-activated', self._on_item_activated)
         self.monitors = []
         view_box = self.ui.get_object('view')
         self.ui.get_object('scrolledWindow').set_placement(Gtk.CornerType.
                                                            TOP_LEFT)
+        self.view.connect('selection-mode-request', self._on_selection_mode_request)
         child_view = self.view.get_children()[0]
         child_view.set_margin_top(64)
         child_view.set_margin_bottom(64)
@@ -159,6 +161,10 @@ class AlbumWidget(Gtk.EventBox):
         self.show_all()
 
     @log
+    def _on_selection_mode_request(self, *args):
+        self.header_bar._select_button.clicked()
+
+    @log
     def _on_item_activated(self, widget, id, path):
         child_path = self.filter.convert_path_to_child_path(path)
         _iter = self.model.get_iter(child_path)
