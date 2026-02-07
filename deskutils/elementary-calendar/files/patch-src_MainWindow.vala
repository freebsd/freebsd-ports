--- src/MainWindow.vala.orig	2021-01-18 04:30:35 UTC
+++ src/MainWindow.vala
@@ -51,8 +51,9 @@ public class Maya.MainWindow : Gtk.ApplicationWindow {
     construct {
         add_action_entries (ACTION_ENTRIES, this);
 
-        foreach (var action in action_accelerators.get_keys ()) {
-            ((Gtk.Application) GLib.Application.get_default ()).set_accels_for_action (ACTION_PREFIX + action, action_accelerators[action].to_array ());
+        var iter = action_accelerators.map_iterator ();
+        while (iter.next ()) {
+            ((Gtk.Application) GLib.Application.get_default ()).set_accels_for_action (ACTION_PREFIX + iter.get_key (), { iter.get_value () });
         }
 
         weak Gtk.IconTheme default_theme = Gtk.IconTheme.get_default ();
