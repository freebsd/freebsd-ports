--- src/components/collections/collections_model.vala.orig	2012-06-17 19:04:56.000000000 +0200
+++ src/components/collections/collections_model.vala	2013-03-08 16:25:01.542854653 +0100
@@ -157,7 +157,7 @@
 		 */
 		public void remove_temporary_playlist ()
 		{
-			remove(_temporary_playlist_iter);
+			remove(ref _temporary_playlist_iter);
 			has_temporary_playlist = false;
 		}
 
@@ -258,7 +258,7 @@
 			}
 
 			while (iter_children(out child, parent)) {
-				remove(child);
+				remove(ref child);
 			}
 
 			int pos = iter_n_children(parent);
@@ -433,7 +433,7 @@
 
 				get(iter, Column.Name, out current);
 				if (name == current) {
-					remove(iter);
+					remove(ref iter);
 					break;
 				}
 			} while (iter_next(ref iter));
