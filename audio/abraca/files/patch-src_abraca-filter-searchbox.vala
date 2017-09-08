--- src/abraca-filter-searchbox.vala.orig	2014-10-26 18:55:55 UTC
+++ src/abraca-filter-searchbox.vala
@@ -78,7 +78,11 @@ public class Abraca.FilterSearchBox : Gtk.ComboBox, Se
 			do {
 				store.get(iter, 0, out current);
 				if (current == pattern) {
+#if VALA_0_36
+					store.remove(ref iter);
+#else
 					store.remove(iter);
+#endif
 					break;
 				}
 			} while (store.iter_next(ref iter));
