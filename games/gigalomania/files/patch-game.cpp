--- game.cpp.orig	2015-09-21 19:36:26 UTC
+++ game.cpp
@@ -105,7 +105,7 @@ Game::Game() {
 	n_sub_epochs = 4;
 	selected_island = 0;
 	for(int i=0;i<max_islands_per_epoch_c;i++) {
-		completed_island[i] = NULL;
+		completed_island[i] = false;
 		for(int j=0;j<n_epochs_c;j++) {
 			maps[j][i] = NULL;
 		}
