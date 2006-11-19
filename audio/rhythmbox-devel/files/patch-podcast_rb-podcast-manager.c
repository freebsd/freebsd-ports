--- podcast/rb-podcast-manager.c.orig	Sun Sep 24 07:03:53 2006
+++ podcast/rb-podcast-manager.c	Sun Nov 19 12:31:44 2006
@@ -85,8 +85,6 @@ struct RBPodcastManagerPrivate
 	guint next_time;
 	guint source_sync;
 	guint update_interval_notify_id;
-	GMutex *mutex_job;
-	GMutex *download_list_mutex;
 
 	gboolean remove_files;
 
@@ -102,7 +100,6 @@ typedef struct
 	RBPodcastChannel 	*channel;
 } RBPodcastManagerEvent;
 
-/* used on donwload thread */
 typedef struct
 {
 	RBPodcastManager *pd;
@@ -111,14 +108,12 @@ typedef struct
 	GnomeVFSURI *write_uri;
 	GnomeVFSURI *read_uri;
 	char *query_string;
-	GMutex *mutex_working;
 
 	guint total_size;
 	guint progress;
 	gboolean canceled;
 } RBPodcastManagerInfo;
 
-/* used on subscribe thread */
 typedef struct
 {
 	RBPodcastManager *pd;
@@ -175,7 +170,6 @@ static guint download_progress_update_cb
 
 /* internal functions */
 static void download_info_free				(RBPodcastManagerInfo *data);
-static RBPodcastManagerInfo *download_info_new		(void);
 static void start_job					(RBPodcastManagerInfo *data);
 static void end_job					(RBPodcastManagerInfo *data);
 static void cancel_job					(RBPodcastManagerInfo *pd);
@@ -272,8 +266,6 @@ rb_podcast_manager_init (RBPodcastManage
 	pd->priv = RB_PODCAST_MANAGER_GET_PRIVATE (pd);
 
 	pd->priv->source_sync = 0;
-	pd->priv->mutex_job = g_mutex_new();
-	pd->priv->download_list_mutex = g_mutex_new();
 	pd->priv->event_queue = g_async_queue_new ();
 	pd->priv->db = NULL;
 	eel_gconf_monitor_add (CONF_STATE_PODCAST_PREFIX);
@@ -321,8 +313,6 @@ rb_podcast_manager_finalize (GObject *ob
 		g_list_free (pd->priv->download_list);
 	}
 
-	g_mutex_free (pd->priv->mutex_job);
-	g_mutex_free (pd->priv->download_list_mutex);
 	g_async_queue_unref (pd->priv->event_queue);
 
 	G_OBJECT_CLASS (rb_podcast_manager_parent_class)->finalize (object);
@@ -418,12 +408,12 @@ rb_podcast_manager_download_entry (RBPod
 			g_value_unset (&status_val);
 		}
 		rb_debug ("Try insert entry for download.");
-		data  = download_info_new();
+
+		data = g_new0 (RBPodcastManagerInfo, 1);
 		data->pd = pd;
 		data->entry = entry;
-        	g_mutex_lock (pd->priv->download_list_mutex);
+
 		pd->priv->download_list =  g_list_append (pd->priv->download_list, data);
-		g_mutex_unlock (pd->priv->download_list_mutex);
 		g_idle_add ((GtkFunction) rb_podcast_manager_next_file , pd);
 	}
 }
@@ -535,23 +525,15 @@ rb_podcast_manager_head_query_cb (GtkTre
 static gboolean
 rb_podcast_manager_next_file (RBPodcastManager * pd)
 {
+	gint size;
+
 	GDK_THREADS_ENTER ();
-	
 	rb_debug ("try lock file_process mutex");
-	if (g_mutex_trylock (pd->priv->mutex_job) == TRUE) {
-		gint size;
 
-		g_mutex_lock (pd->priv->download_list_mutex);
-		size = g_list_length (pd->priv->download_list);
-		g_mutex_unlock (pd->priv->download_list_mutex);
-
-		if (size > 0)
-			rb_podcast_manager_copy_post (pd);
-		else
-			g_mutex_unlock (pd->priv->mutex_job);
-	} else {
-		rb_debug ("not start");
-	}
+	size = g_list_length (pd->priv->download_list);
+
+	if (size > 0)
+		rb_podcast_manager_copy_post (pd);
 
 	GDK_THREADS_LEAVE ();
 	return FALSE;
@@ -565,9 +547,7 @@ rb_podcast_manager_copy_post (RBPodcastM
 	char *query_string;
 
 	/* get first element of list */
-	g_mutex_lock (pd->priv->download_list_mutex);
 	data = (RBPodcastManagerInfo *) g_list_first (pd->priv->download_list)->data;
-	g_mutex_unlock (pd->priv->download_list_mutex);
 
 	g_assert (data != NULL);
 	g_assert (data->entry != NULL);
@@ -765,13 +745,9 @@ rb_podcast_manager_abort_download (RBPod
 {
 	RBPodcastManager *mgr = data->pd;
 
-	g_mutex_lock (mgr->priv->download_list_mutex);
 	mgr->priv->download_list = g_list_remove (mgr->priv->download_list, (gconstpointer) data);
-	g_mutex_unlock (mgr->priv->download_list_mutex);
-
 	download_info_free (data);
 
-	g_mutex_unlock (mgr->priv->mutex_job);
 	g_idle_add ((GtkFunction) rb_podcast_manager_next_file, mgr);
 }
 
@@ -1021,6 +997,8 @@ write_job_data (RBPodcastManagerInfo *da
 		       			   gnome_vfs_uri_to_string (data->write_uri, GNOME_VFS_URI_HIDE_NONE));
 
 	rhythmdb_commit (db);
+
+	end_job (data);
 }
 
 static void
@@ -1040,19 +1018,9 @@ download_info_free (RBPodcastManagerInfo
 		data->query_string = NULL;
 	}
 
-	g_mutex_free (data->mutex_working);
-
 	g_free (data);
 }
 
-static RBPodcastManagerInfo*
-download_info_new (void)
-{
-	RBPodcastManagerInfo *data = g_new0 (RBPodcastManagerInfo, 1);
-	data->mutex_working = g_mutex_new ();
-	return data;
-}
-
 static void
 start_job (RBPodcastManagerInfo *data)
 {
@@ -1070,8 +1038,6 @@ start_job (RBPodcastManagerInfo *data)
 	source_uri_list = g_list_prepend (source_uri_list, data->read_uri);
 	target_uri_list = g_list_prepend (target_uri_list, data->write_uri);
 
-	g_mutex_lock (data->mutex_working);
-
 	rb_debug ("start async copy");
 	gnome_vfs_async_xfer ( &data->read_handle,
 				source_uri_list,
@@ -1094,9 +1060,7 @@ rb_podcast_manager_cancel_all	(RBPodcast
 	guint lst_len;
 	GList *lst;
 
-	g_mutex_lock (pd->priv->download_list_mutex);
 	lst = g_list_reverse (pd->priv->download_list);
-	g_mutex_unlock (pd->priv->download_list_mutex);
 
 	rb_debug ("cancel all job %d", g_list_length (lst));
 	lst_len = g_list_length (lst);
@@ -1107,11 +1071,6 @@ rb_podcast_manager_cancel_all	(RBPodcast
 		cancel_job (data);
 		rb_debug ("cancel next job");
 	}
-
-	if (lst_len > 0) {
-		g_mutex_lock (pd->priv->mutex_job);
-		g_mutex_unlock (pd->priv->mutex_job);
-	}
 }
 
 static void
@@ -1120,12 +1079,7 @@ end_job	(RBPodcastManagerInfo *data)
 	RBPodcastManager *pd = data->pd;
 
 	rb_debug ("end_job");
-
-	g_mutex_lock (data->pd->priv->download_list_mutex);
 	data->pd->priv->download_list = g_list_remove (data->pd->priv->download_list, (gconstpointer) data);
-	g_mutex_unlock (data->pd->priv->download_list_mutex);
-
-	g_mutex_unlock (data->mutex_working);
 
 	if (data->canceled != TRUE) {
 		GDK_THREADS_ENTER ();
@@ -1137,7 +1091,6 @@ end_job	(RBPodcastManagerInfo *data)
 	}
 
 	download_info_free (data);
-	g_mutex_unlock (pd->priv->mutex_job);
 
 	g_idle_add ((GtkFunction) rb_podcast_manager_next_file, pd);
 }
@@ -1145,22 +1098,12 @@ end_job	(RBPodcastManagerInfo *data)
 static void
 cancel_job (RBPodcastManagerInfo *data)
 {
-	if (g_mutex_trylock (data->mutex_working) == FALSE) {
-		rb_debug ("async cancel");
-		data->canceled = TRUE;
-	}
-	else {
-		rb_debug ("job cancel");
-
-		g_mutex_lock (data->pd->priv->download_list_mutex);
-		data->pd->priv->download_list = g_list_remove (data->pd->priv->download_list, (gconstpointer ) data);
-		g_mutex_unlock (data->pd->priv->download_list_mutex);
+	rb_debug ("job cancel");
 
-		g_mutex_unlock (data->mutex_working);
+	data->pd->priv->download_list = g_list_remove (data->pd->priv->download_list, (gconstpointer ) data);
 
-		download_info_free (data);
-		data = NULL;
-	}
+	download_info_free (data);
+	data = NULL;
 }
 
 static guint
@@ -1175,16 +1118,16 @@ download_progress_cb (GnomeVFSXferProgre
 	if (info->status != GNOME_VFS_XFER_PROGRESS_STATUS_OK ||
 	    ((info->phase == GNOME_VFS_XFER_PHASE_COMPLETED) && (info->file_size == 0))) {
 		GValue val = {0, };
+
 		rb_debug ("error on download");
+
 		g_value_init (&val, G_TYPE_ULONG);
 		g_value_set_ulong (&val, RHYTHMDB_PODCAST_STATUS_ERROR);
-		GDK_THREADS_ENTER ();
 		rhythmdb_entry_set (data->pd->priv->db, data->entry, RHYTHMDB_PROP_STATUS,  &val);
 		rhythmdb_commit (data->pd->priv->db);
-		GDK_THREADS_LEAVE ();
 		g_value_unset (&val);
-		end_job (data);
-		data = NULL;
+
+		g_idle_add ((GSourceFunc)end_job, data);
 		return GNOME_VFS_XFER_ERROR_ACTION_ABORT;
 	}
 
@@ -1208,9 +1151,9 @@ download_progress_cb (GnomeVFSXferProgre
 			rb_debug ("download completed");
 			data->total_size = info->file_size;
 			write_job_data (data);
+		} else {
+			g_idle_add ((GSourceFunc)end_job, data);
 		}
-		end_job (data);
-		data = NULL;
 		return GNOME_VFS_XFER_ERROR_ACTION_SKIP;
 	}
 
@@ -1226,7 +1169,6 @@ download_progress_cb (GnomeVFSXferProgre
 static guint
 download_progress_update_cb (GnomeVFSAsyncHandle *handle, GnomeVFSXferProgressInfo *info, gpointer cb_data)
 {
-
 	RBPodcastManagerInfo *data = (RBPodcastManagerInfo *) cb_data;
 
 	if (data == NULL) {
@@ -1243,17 +1185,18 @@ download_progress_update_cb (GnomeVFSAsy
 		if (local_progress != data->progress) {
 			GValue val = {0,};
 
+			GDK_THREADS_ENTER ();
+
 			g_value_init (&val, G_TYPE_ULONG);
 			g_value_set_ulong (&val, local_progress);
 			rhythmdb_entry_set (data->pd->priv->db, data->entry, RHYTHMDB_PROP_STATUS, &val);
 			g_value_unset (&val);
 
-			GDK_THREADS_ENTER ();
-
 			g_signal_emit (data->pd, rb_podcast_manager_signals[STATUS_CHANGED],
 				       0, data->entry, local_progress);
 
 			GDK_THREADS_LEAVE ();
+
 			data->progress = local_progress;
 		}
 	}
@@ -1368,8 +1311,6 @@ rb_podcast_manager_cancel_download (RBPo
 {
 	GList *lst;
 
-	g_mutex_lock (pd->priv->download_list_mutex);
-
 	lst = pd->priv->download_list;
 	while (lst) {
 		RBPodcastManagerInfo *data = (RBPodcastManagerInfo *) lst->data;
@@ -1379,7 +1320,6 @@ rb_podcast_manager_cancel_download (RBPo
 		}
 		lst = lst->next;
 	}
-	g_mutex_unlock (pd->priv->download_list_mutex);
 
 	if (lst)
 		cancel_job (lst->data);
