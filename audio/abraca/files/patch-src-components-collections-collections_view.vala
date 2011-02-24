--- src/components/collections/collections_view.vala.orig	2010-04-03 04:19:53.000000000 +0200
+++ src/components/collections/collections_view.vala	2010-11-12 20:11:48.471315596 +0100
@@ -441,16 +441,11 @@
 				Gtk.TreePath path = model.get_path(iter);
 
 				if (path.get_depth() == 2) {
-					unowned GLib.List<Gtk.CellRenderer> renderers;
-					Gtk.CellRendererText renderer;
-					GLib.List<unowned Gtk.TreeViewColumn> cols;
-					Gtk.TreeViewColumn col;
+					var cols = get_columns();
+					var col = cols.data;
 
-					cols = get_columns();
-					col = cols.data;
-
-					renderers = col.get_cells();
-					renderer = (Gtk.CellRendererText) renderers.data;
+					var renderers = col.get_cells();
+					var renderer = (Gtk.CellRendererText) renderers.data;
 
 					renderer.editable = true;
 					set_cursor_on_cell(path, col, renderer, true);
