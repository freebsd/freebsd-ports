diff --git a/gnomemusic/window.py b/gnomemusic/window.py
index 33c49b9..fc59150 100644
--- gnomemusic/window.py
+++ gnomemusic/window.py
@@ -116,17 +116,17 @@ class Window(Gtk.ApplicationWindow):
         if cursor is not None and cursor.next(None):
             count = cursor.get_integer(0)
         if not count > 0:
-            print("switching to Empty view")
-            self._stack.disconnect(self._on_notify_model_id)
-            self.disconnect(self._key_press_event_id)
-            for i in range(0, 4):
-                view = self.views.pop()
-                view.destroy()
-            self.toolbar.hide_stack()
-            self._switch_to_empty_view()
+            if self.toolbar._selectionMode is False and len(self.views) != 1:
+                self._stack.disconnect(self._on_notify_model_id)
+                self.disconnect(self._key_press_event_id)
+                view_count = len(self.views)
+                for i in range(0, view_count):
+                    view = self.views.pop()
+                    view.destroy()
+                self.toolbar.hide_stack()
+                self._switch_to_empty_view()
         else:
             if (self.views[0] == self.views[-1]):
-                print("switching to player view")
                 view = self.views.pop()
                 view.destroy()
                 self._switch_to_player_view()
@@ -207,7 +207,8 @@ class Window(Gtk.ApplicationWindow):
             self._switch_to_player_view()
         # To revert to the No Music View when no songs are found
         else:
-            self._switch_to_empty_view()
+            if self.toolbar._selectionMode is False:
+                self._switch_to_empty_view()
 
         self.toolbar._search_button.connect('toggled', self._on_search_toggled)
         self.toolbar.connect('selection-mode-changed', self._on_selection_mode_changed)
@@ -340,7 +341,9 @@ class Window(Gtk.ApplicationWindow):
 
     @log
     def _on_selection_mode_changed(self, widget, data=None):
-        if self.toolbar._selectionMode:
+        if self.toolbar._selectionMode is False:
+            self._on_changes_pending()
+        else:
             in_playlist = self._stack.get_visible_child() == self.views[3]
             self.selection_toolbar._add_to_playlist_button.set_visible(not in_playlist)
             self.selection_toolbar._remove_from_playlist_button.set_visible(in_playlist)
