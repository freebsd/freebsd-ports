https://github.com/glandium/git-cinnabar/commit/cf440d651b37

--- helper/cinnabar-helper.c.orig	2018-09-29 22:45:54 UTC
+++ helper/cinnabar-helper.c
@@ -1461,7 +1461,7 @@ static void upgrade_files(const struct old_manifest_tr
 				goto corrupted;
 		}
 		display_progress(track->progress,
-		                 hashmap_get_size(&track->set.map.map));
+		                 kh_size(&track->set.set));
 	}
 
 	free_tree_buffer(state.tree_git);
