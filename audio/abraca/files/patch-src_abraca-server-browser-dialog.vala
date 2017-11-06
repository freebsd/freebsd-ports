--- src/abraca-server-browser-dialog.vala.orig	2014-10-26 18:55:55 UTC
+++ src/abraca-server-browser-dialog.vala
@@ -145,7 +145,11 @@ public class Abraca.ServerBrowserDialog : Gtk.Dialog
 			unowned string entry_name, entry_path;
 			location_store.get(iter, Column.NAME, out entry_name, Column.PATH, out entry_path);
 			if (path == entry_path) {
+#if VALA_0_36
+				location_store.remove(ref iter);
+#else
 				location_store.remove(iter);
+#endif
 				break;
 			}
 		} while (location_store.iter_next(ref iter));
