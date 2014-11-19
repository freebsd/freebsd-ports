--- src/gimmix-playlist.c.orig	2014-11-06 23:11:16.079445577 +0100
+++ src/gimmix-playlist.c	2014-11-06 23:13:09.287439112 +0100
@@ -39,7 +39,7 @@
 
 typedef enum {
 	SONG = 1,
-	DIR,
+	GIMMIXDIR,
 	PLAYLIST
 } GimmixFileType;
 
@@ -149,7 +149,7 @@
 		gtk_tree_model_get_iter (model, &iter, list->data);
 		gtk_tree_model_get (model, &iter, 2, &path, 3, &type, -1);
 		
-		if (type == DIR || type == SONG)
+		if (type == GIMMIXDIR || type == SONG)
 		{
 			switch (target_type)
 			{
@@ -671,7 +671,7 @@
 						GDK_TYPE_PIXBUF, 	/* icon (0) */
 						G_TYPE_STRING, 		/* name (1) */
 						G_TYPE_STRING,		/* path (2) */
-						G_TYPE_INT,			/* type DIR/SONG (3) */
+						G_TYPE_INT,			/* type GIMMIXDIR/SONG (3) */
 						G_TYPE_INT);		/* id (4) */
 	
 	pls_store 	= gtk_list_store_new (2, 
@@ -696,7 +696,7 @@
 						0, dir_pixbuf,
 						1, path,
 						2, data->directory,
-						3, DIR,
+						3, GIMMIXDIR,
 						-1);
 			g_free (path);
 		}
@@ -954,7 +954,7 @@
 		gtk_tree_model_get_iter (model, &iter, list->data);
 		gtk_tree_model_get (model, &iter, 2, &path, 3, &type, -1);
 		
-		if (type == DIR)
+		if (type == GIMMIXDIR)
 		{	
 			gimmix_update_library_with_dir (path);
 		}
@@ -1005,7 +1005,7 @@
 		gtk_tree_model_get_iter (model, &iter, list->data);
 		gtk_tree_model_get (model, &iter, 2, &path, 3, &type, -1);
 		
-		if (type == DIR)
+		if (type == GIMMIXDIR)
 		{
 			mpd_playlist_queue_add (gmo, path);
 		}
@@ -1023,7 +1023,7 @@
 		gtk_tree_model_get (model, &iter, 2, &path, 3, &type, -1);
 	
 		
-		if (type == DIR)
+		if (type == GIMMIXDIR)
 		{	
 			mpd_playlist_queue_add (gmo, path);
 			g_free (path);
@@ -1081,7 +1081,7 @@
 		gtk_tree_model_get_iter (model, &iter, list->data);
 		gtk_tree_model_get (model, &iter, 2, &path, 3, &type, -1);
 		
-		if (type == DIR)
+		if (type == GIMMIXDIR)
 		{
 			mpd_playlist_queue_add (gmo, path);
 		}
@@ -1099,7 +1099,7 @@
 		gtk_tree_model_get (model, &iter, 2, &path, 3, &type, -1);
 	
 		
-		if (type == DIR)
+		if (type == GIMMIXDIR)
 		{	
 			mpd_playlist_queue_add (gmo, path);
 			g_free (path);
@@ -1245,7 +1245,7 @@
 					0, dir_pixbuf,
 					1, "..",
 					2, parent,
-					3, DIR,
+					3, GIMMIXDIR,
 					-1);
 		g_free (parent);
 	}
@@ -1260,7 +1260,7 @@
 								0, dir_pixbuf,
 								1, directory,
 								2, data->directory,
-								3, DIR,
+								3, GIMMIXDIR,
 								-1);
 			g_free (directory);
 		}
@@ -1341,7 +1341,7 @@
 	gtk_tree_model_get_iter (model, &iter, list->data);
 	gtk_tree_model_get (model, &iter, 2, &path, 3, &type, 4, &id, -1);
 
-	if (type == DIR)
+	if (type == GIMMIXDIR)
 	{
 		g_free (path);
 		return;
