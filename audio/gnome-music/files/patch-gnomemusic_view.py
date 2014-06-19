diff --git a/gnomemusic/view.py b/gnomemusic/view.py
index e2e6cd7..40f783f 100644
--- gnomemusic/view.py
+++ gnomemusic/view.py
@@ -131,7 +131,6 @@ class ViewContainer(Stack):
         box.pack_end(self._loadMore.widget, False, False, 0)
         self._loadMore.widget.connect('clicked', self._populate)
         self.view.connect('item-activated', self._on_item_activated)
-        self.view.connect('selection-mode-request', self._on_selection_mode_request)
         self._cursor = None
         self.header_bar = header_bar
         self.header_bar._select_button.connect(
@@ -372,11 +372,17 @@ class Albums(ViewContainer):
 
     @log
     def _on_changes_pending(self, data=None):
-        if (self._init):
+        if (self._init and self.header_bar._selectionMode is False):
             self._offset = 0
             self._cached_count = -1
             self._model.clear()
             self.populate()
+            grilo.changes_pending['Albums'] = False
+
+    @log
+    def _on_selection_mode_changed(self, widget, data=None):
+        if self.header_bar._selectionMode is False and grilo.changes_pending['Albums'] is True:
+            self._on_changes_pending()
 
     @log
     def _back_button_clicked(self, widget, data=None):
@@ -459,11 +465,17 @@ class Songs(ViewContainer):
 
     @log
     def _on_changes_pending(self, data=None):
-        if (self._init):
+        if (self._init and self.header_bar._selectionMode is False):
             self._model.clear()
             self._offset = 0
             self._cached_count = -1
             self.populate()
+            grilo.changes_pending['Songs'] = False
+
+    @log
+    def _on_selection_mode_changed(self, widget, data=None):
+        if self.header_bar._selectionMode is False and grilo.changes_pending['Songs'] is True:
+            self._on_changes_pending()
 
     @log
     def _on_item_activated(self, widget, id, path):
@@ -646,12 +658,13 @@ class Artists (ViewContainer):
 
     @log
     def _on_changes_pending(self, data=None):
-        if (self._init):
+        if (self._init and self.header_bar._selectionMode is False):
             self._model.clear()
             self._artists.clear()
             self._offset = 0
             self._cached_count = -1
             self._populate()
+            grilo.changes_pending['Artists'] = False
 
     @log
     def _populate(self, data=None):
@@ -763,6 +776,12 @@ class Artists (ViewContainer):
                     self._last_selection)
 
     @log
+    def _on_selection_mode_changed(self, widget, data=None):
+        self.artistAlbumsStack.set_sensitive(not self.header_bar._selectionMode)
+        if self.header_bar._selectionMode is False and grilo.changes_pending['Artists'] is True:
+            self._on_changes_pending()
+
+    @log
     def get_selected_track_uris(self, callback):
         self.items_selected = []
         self.items_selected_callback = callback
@@ -1089,6 +1108,7 @@ class Playlist(ViewContainer):
         self.playlists_sidebar.set_sensitive(not self.header_bar._selectionMode)
         self.menubutton.set_sensitive(not self.header_bar._selectionMode)
 
+
     @log
     def _on_play_activate(self, menuitem, data=None):
         _iter = self._model.get_iter_first()

