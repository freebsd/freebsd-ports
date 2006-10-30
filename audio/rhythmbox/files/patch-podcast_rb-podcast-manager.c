--- podcast/rb-podcast-manager.c.orig	Sun Sep 24 07:03:53 2006
+++ podcast/rb-podcast-manager.c	Fri Oct 27 10:21:17 2006
@@ -545,10 +545,12 @@ rb_podcast_manager_next_file (RBPodcastM
 		size = g_list_length (pd->priv->download_list);
 		g_mutex_unlock (pd->priv->download_list_mutex);
 
-		if (size > 0)
+		if (size > 0) {
 			rb_podcast_manager_copy_post (pd);
-		else
 			g_mutex_unlock (pd->priv->mutex_job);
+		} else {
+			g_mutex_unlock (pd->priv->mutex_job);
+		}
 	} else {
 		rb_debug ("not start");
 	}
@@ -635,6 +637,7 @@ rb_podcast_manager_download_file_info_cb
 
 	rb_debug ("got file info results for %s",
 		  rhythmdb_entry_get_string (data->entry, RHYTHMDB_PROP_LOCATION));
+	g_mutex_lock (data->pd->priv->mutex_job);
 
 	if (result->result != GNOME_VFS_OK) {
 
@@ -769,6 +772,7 @@ rb_podcast_manager_abort_download (RBPod
 	mgr->priv->download_list = g_list_remove (mgr->priv->download_list, (gconstpointer) data);
 	g_mutex_unlock (mgr->priv->download_list_mutex);
 
+	g_mutex_unlock (data->mutex_working);
 	download_info_free (data);
 
 	g_mutex_unlock (mgr->priv->mutex_job);
@@ -1085,6 +1089,10 @@ start_job (RBPodcastManagerInfo *data)
 				(GnomeVFSXferProgressCallback ) download_progress_cb,
 				data);
 
+	g_mutex_unlock (data->mutex_working);
+
+	g_mutex_unlock (data->pd->priv->mutex_job);
+
 }
 
 void
@@ -1170,6 +1178,11 @@ download_progress_cb (GnomeVFSXferProgre
 
 	if (data == NULL) {
 		return GNOME_VFS_XFER_ERROR_ACTION_ABORT;
+	}
+
+	if (info->phase == GNOME_VFS_XFER_PHASE_INITIAL) {
+		g_mutex_lock (data->mutex_working);
+		g_mutex_lock (data->pd->priv->mutex_job);
 	}
 
 	if (info->status != GNOME_VFS_XFER_PROGRESS_STATUS_OK ||
