--- libedataserver/e-msgport.c.orig	Sat Dec 10 07:31:28 2005
+++ libedataserver/e-msgport.c	Mon Dec 19 02:19:10 2005
@@ -1069,9 +1069,18 @@ thread_dispatch(void *din)
 void e_thread_put(EThread *e, EMsg *msg)
 {
 	pthread_t id;
+	pthread_attr_t attr;
 	EMsg *dmsg = NULL;
 
 	pthread_mutex_lock(&e->mutex);
+	pthread_attr_init(&attr);
+	/* Give us a 1 MB thread stacksize on 32-bit architectures, and
+	 * a 2 MB thread stacksize on 64-bit architectures. */
+	if (sizeof (void *) == 8) {
+		pthread_attr_setstacksize(&attr, 0x200000);
+	} else {
+		pthread_attr_setstacksize(&attr, 0x100000);
+	}
 
 	/* the caller forgot to tell us what to do, well, we can't do anything can we */
 	if (e->received == NULL) {
@@ -1110,13 +1119,14 @@ void e_thread_put(EThread *e, EMsg *msg)
 		e_msgport_put(e->server_port, msg);
 		if (e->waiting == 0
 		    && g_list_length(e->id_list) < e->queue_limit
-		    && pthread_create(&id, NULL, thread_dispatch, e) == 0) {
+		    && pthread_create(&id, &attr, thread_dispatch, e) == 0) {
 			struct _thread_info *info = g_malloc0(sizeof(*info));
 			t(printf("created NEW thread %" G_GUINT64_FORMAT "\n", e_util_pthread_id(id)));
 			info->id = id;
 			info->busy = TRUE;
 			e->id_list = g_list_append(e->id_list, info);
 		}
+		pthread_attr_destroy(&attr);
 		pthread_mutex_unlock(&e->mutex);
 		return;
 	}
@@ -1125,13 +1135,14 @@ void e_thread_put(EThread *e, EMsg *msg)
 	if (!e->have_thread) {
 		int err;
 
-		if ((err = pthread_create(&e->id, NULL, thread_dispatch, e)) != 0) {
+		if ((err = pthread_create(&e->id, &attr, thread_dispatch, e)) != 0) {
 			g_warning("Could not create dispatcher thread, message queued?: %s", strerror(err));
 		} else {
 			e->have_thread = TRUE;
 		}
 	}
 
+	pthread_attr_destroy(&attr);
 	pthread_mutex_unlock(&e->mutex);
 
 	if (dmsg) {
