--- libeog/eog-info-view.c.orig	Wed Oct 13 16:42:12 2004
+++ libeog/eog-info-view.c	Wed Oct 13 16:43:41 2004
@@ -246,6 +246,7 @@
 	EogInfoView *view;
 	EogInfoViewPrivate *priv;
 	char *path;
+	char entryval[4096];
 
 	view = EOG_INFO_VIEW (data);
 	priv = view->priv;
@@ -255,11 +256,11 @@
 	path = g_hash_table_lookup (priv->id_path_hash, GINT_TO_POINTER (entry->tag));
 
 	if (path != NULL) {
-		set_row_data (store, path, exif_tag_get_name (entry->tag), exif_entry_get_value (entry));	
+		set_row_data (store, path, exif_tag_get_name (entry->tag), exif_entry_get_value (entry, entryval, sizeof(entryval)));	
 	}
 	else {
 		path = set_row_data (store, NULL, 
-				     exif_tag_get_name (entry->tag), exif_entry_get_value (entry));	
+				     exif_tag_get_name (entry->tag), exif_entry_get_value (entry, entryval, sizeof(entryval)));	
 
 		g_hash_table_insert (priv->id_path_hash,
 				     GINT_TO_POINTER (entry->tag),
