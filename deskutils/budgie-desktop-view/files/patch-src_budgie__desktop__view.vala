In GLib, we use the kqueue backend, and GLib.FileMonitorFlags.WATCH_MOVES
enum is not available for us. If we send something in trash bin, icon is not
updated (despite right signal).

--- src/budgie_desktop_view.vala.orig	2022-03-06 16:37:45 UTC
+++ src/budgie_desktop_view.vala
@@ -123,7 +123,7 @@ public class DesktopView : Gtk.ApplicationWindow {
 		desktop_file = File.new_for_path(desktop_file_uri); // Get the Desktop folder "file"
 
 		try {
-			desktop_monitor = desktop_file.monitor(FileMonitorFlags.WATCH_MOVES, null); // Create our file monitor
+			desktop_monitor = desktop_file.monitor(FileMonitorFlags.NONE, null); // Create our file monitor
 			desktop_monitor.changed.connect(on_file_changed); // Bind to our file changed event
 		} catch (Error e) {
 			warning("Failed to obtain a monitor for file changes to the Desktop folder. Will not be able to watch for changes: %s", e.message);
