--- src/components/playlist/playlist_model.vala.orig	2010-04-03 04:19:53.000000000 +0200
+++ src/components/playlist/playlist_model.vala	2010-11-21 22:17:26.000000000 +0100
@@ -136,9 +136,9 @@
 			if (iter_nth_child (out iter, null, pos) &&
 			    iter_nth_child(out niter, null, npos)) {
 				if (pos < npos) {
-					move_after (iter, niter);
+					move_after (ref iter, niter);
 				} else {
-					move_before (iter, niter);
+					move_before (ref iter, niter);
 				}
 			}
 		}
