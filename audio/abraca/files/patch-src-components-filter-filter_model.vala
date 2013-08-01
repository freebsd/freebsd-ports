--- src/components/filter/filter_model.vala.orig	2012-06-17 19:04:56.000000000 +0200
+++ src/components/filter/filter_model.vala	2013-07-31 18:17:53.287738608 +0200
@@ -117,7 +117,7 @@
 		 * When GTK asks for the value of a column, check if the row
 		 * has been resolved or not, otherwise resolve it.
 		 */
-		public void get_value (Gtk.TreeIter iter, int column, ref GLib.Value val)
+		public void get_value (Gtk.TreeIter iter, int column, out GLib.Value val)
 		{
 			GLib.Value tmp1;
 
