--- src/display_playlists.c.orig	Tue Oct 18 22:20:51 2005
+++ src/display_playlists.c	Tue Oct 18 22:22:11 2005
@@ -1142,6 +1142,11 @@
                     (useful when quitting program) */
 void pm_remove_playlist (Playlist *playlist, gboolean select)
 {
+    GtkTreeModel *model;
+    gboolean have_iter = FALSE;
+    GtkTreeIter i;
+    GtkTreeSelection *ts = NULL;
+
     gboolean pm_delete_playlist_fe (GtkTreeModel *model,
 					   GtkTreePath *path,
 					   GtkTreeIter *iter,
@@ -1156,10 +1161,6 @@
 	    }
 	    return FALSE;
 	};
-    GtkTreeModel *model;
-    gboolean have_iter = FALSE;
-    GtkTreeIter i;
-    GtkTreeSelection *ts = NULL;
 
   g_return_if_fail (playlist);
   model = gtk_tree_view_get_model (playlist_treeview);
