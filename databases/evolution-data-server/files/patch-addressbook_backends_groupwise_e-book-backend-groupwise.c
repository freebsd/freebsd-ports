--- addressbook/backends/groupwise/e-book-backend-groupwise.c.orig	Fri Sep  2 16:37:43 2005
+++ addressbook/backends/groupwise/e-book-backend-groupwise.c	Thu Nov 10 09:55:01 2005
@@ -2010,6 +2010,7 @@
 	if (enable_debug)
 		printf ("\nread contacts from cache for the ids found in summary\n");
 	for (i = 0; i < ids->len; i ++) {
+		EContact *contact;
 		char *uid = g_ptr_array_index (ids, i);
 
 		g_mutex_lock (closure->mutex);
@@ -2019,8 +2020,7 @@
 		if (stopped)
 			break;	
 
-		EContact *contact = 
-			e_book_backend_cache_get_contact (priv->cache, uid);
+		contact = e_book_backend_cache_get_contact (priv->cache, uid);
 		e_data_book_view_notify_update (book_view, contact);
 		g_object_unref (contact);
 	}
@@ -2697,6 +2697,13 @@
 	EBookBackendGroupwisePrivate *priv = ebgw->priv;
 	EBookBackendCache *cache = priv->cache;
 
+	struct timeval start, end;
+	unsigned long diff;
+	const char *cache_file_name;
+	struct stat buf;
+	time_t mod_time;
+
+
 	if (enable_debug)
 		printf("\nupdating GroupWise system address book cache \n");
 		
@@ -2741,12 +2748,6 @@
 				       server_last_sequence, server_last_po_rebuild_time);
 		return TRUE;
 	}
-
-	struct timeval start, end;
-	unsigned long diff;
-	const char *cache_file_name;
-	struct stat buf;
-	time_t mod_time;
 
 	if (enable_debug)
 		gettimeofday(&start, NULL);
