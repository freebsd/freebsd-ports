--- src/components/playlist/playlist_model.vala.orig	2012-06-17 19:04:56.000000000 +0200
+++ src/components/playlist/playlist_model.vala	2013-07-31 18:19:16.480732632 +0200
@@ -85,7 +85,7 @@
 		 * When GTK asks for the value of a column, check if the row
 		 * has been resolved or not, otherwise resolve it.
 		 */
-		public void get_value(Gtk.TreeIter iter, int column, ref GLib.Value val) {
+		public void get_value(Gtk.TreeIter iter, int column, out GLib.Value val) {
 			GLib.Value status;
 
 			base.get_value(iter, Column.STATUS, out status);
