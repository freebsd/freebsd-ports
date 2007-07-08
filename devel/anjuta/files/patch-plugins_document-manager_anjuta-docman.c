--- plugins/document-manager/anjuta-docman.c.orig	Sun Jul  8 03:12:10 2007
+++ plugins/document-manager/anjuta-docman.c	Sun Jul  8 03:20:22 2007
@@ -902,6 +902,7 @@ anjuta_docman_goto_file_line_mark (Anjut
 	const gchar *linenum;
 	glong lineno;
 	gboolean is_local_uri;
+	gchar normalized_path_buf[PATH_MAX];
 	gchar *normalized_path = NULL;
 	
 	IAnjutaEditor *te;
@@ -926,9 +927,9 @@ anjuta_docman_goto_file_line_mark (Anjut
 	/* Get the normalized file path for comparision */
 	is_local_uri = gnome_vfs_uri_is_local (vfs_uri);
 	if (is_local_uri)
-		normalized_path = realpath (gnome_vfs_uri_get_path (vfs_uri), NULL);
+		normalized_path = realpath (gnome_vfs_uri_get_path (vfs_uri), normalized_path_buf);
 	if (normalized_path == NULL)
-		normalized_path = g_strdup (uri);
+		(void) strlcpy (normalized_path, uri, PATH_MAX);
 	
 	gnome_vfs_uri_unref (vfs_uri);
 	/* g_free(filename); */
@@ -942,6 +943,7 @@ anjuta_docman_goto_file_line_mark (Anjut
 		AnjutaDocmanPage *page;
 		gboolean te_is_local_uri;
 		gchar *te_uri;
+		char te_normalized_path_buf[PATH_MAX];
 		gchar *te_normalized_path = NULL;
 		
 		page = (AnjutaDocmanPage *) node->data;
@@ -959,9 +961,9 @@ anjuta_docman_goto_file_line_mark (Anjut
 		te_is_local_uri = gnome_vfs_uri_is_local (vfs_uri);
 		if (te_is_local_uri)
 			te_normalized_path = realpath (gnome_vfs_uri_get_path (vfs_uri),
-										   NULL);
+										   te_normalized_path_buf);
 		if (te_normalized_path == NULL)
-			te_normalized_path = g_strdup (te_uri);
+			(void) strlcpy (te_normalized_path, te_uri, PATH_MAX);
 		gnome_vfs_uri_unref (vfs_uri);
 		
 		if (strcmp (normalized_path, te_normalized_path) == 0)
@@ -982,12 +984,9 @@ anjuta_docman_goto_file_line_mark (Anjut
 			an_file_history_push (te_uri, lineno);
 			g_free (uri);
 			g_free (te_uri);
-			g_free (normalized_path);
-			g_free (te_normalized_path);
 			return te;
 		}
 		g_free (te_uri);
-		g_free (te_normalized_path);
 		node = g_list_next (node);
 	}
 	te = anjuta_docman_add_editor (docman, uri, NULL);
@@ -1006,7 +1005,6 @@ anjuta_docman_goto_file_line_mark (Anjut
 		}
 	}
 	g_free (uri);
-	g_free (normalized_path);
 	return te ;
 }
 
