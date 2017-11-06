--- src/abraca-playlist-model.vala.orig	2014-10-26 18:55:55 UTC
+++ src/abraca-playlist-model.vala
@@ -136,7 +136,11 @@ namespace Abraca {
 				get(iter, Column.ID, out mid);
 
 				playlist_map.remove_path((int) mid, path);
+#if VALA_0_36
+				remove(ref iter);
+#else
 				remove(iter);
+#endif
 			}
 		}
 
