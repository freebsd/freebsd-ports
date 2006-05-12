--- libgnomevfs/gnome-vfs-monitor.c.orig	Fri May 12 20:46:39 2006
+++ libgnomevfs/gnome-vfs-monitor.c	Fri May 12 22:29:57 2006
@@ -48,9 +48,6 @@
 	
 	GList *pending_callbacks; /* protected by handle_hash */
 	guint pending_timeout; /* protected by handle_hash */
-	guint timeout_count; /* count up each time pending_timeout is changed
-				to avoid timeout remove race.
-				protected by handle_hash */
 };
 
 struct GnomeVFSMonitorCallbackData {
@@ -69,6 +66,9 @@
 static GHashTable *handle_hash = NULL;
 G_LOCK_DEFINE_STATIC (handle_hash);
 
+static gint actually_dispatch_callback (gpointer data);
+static guint32 get_min_delay  (GList *list, gint32 now);
+
 static void 
 init_hash_table (void)
 {
@@ -202,17 +202,25 @@
 	return result;
 }
 
+static void
+install_timeout (GnomeVFSMonitorHandle *monitor_handle, time_t now)
+{
+	guint32 delay;
 
-typedef struct {
-	guint timeout_count;
-	GnomeVFSMonitorHandle *monitor_handle;
-} DispatchData;
+	if (monitor_handle->pending_timeout) 
+		g_source_remove (monitor_handle->pending_timeout);
+
+	delay = get_min_delay (monitor_handle->pending_callbacks, now);
+	if (delay == 0)
+		monitor_handle->pending_timeout = g_idle_add (actually_dispatch_callback, monitor_handle);
+	else
+		monitor_handle->pending_timeout = g_timeout_add (delay * 1000, actually_dispatch_callback, monitor_handle);
+}
 
 static gint
 actually_dispatch_callback (gpointer data)
 {
-	DispatchData *ddata = data;
-	GnomeVFSMonitorHandle *monitor_handle = ddata->monitor_handle;
+	GnomeVFSMonitorHandle *monitor_handle = data;
 	GnomeVFSMonitorCallbackData *callback_data;
 	gchar *uri;
 	GList *l, *next;
@@ -228,13 +236,6 @@
 
 	G_LOCK (handle_hash);
 
-	/* Don't clear pending_timeout if we started another timeout
-	 * (and removed this)
-	 */
-	if (monitor_handle->timeout_count == ddata->timeout_count) {
-		monitor_handle->pending_timeout = 0;
-	}
-
 	if (!monitor_handle->cancelled) {
 		/* Find all callbacks that needs to be dispatched */
 		dispatch = NULL;
@@ -305,13 +306,17 @@
 
 	}
 
-	/* if we were waiting for this callback to be dispatched to free
-	 * this monitor, then do it now.
-	 */
-	if (monitor_handle->cancelled &&
-	    no_live_callbacks (monitor_handle)) {
-		destroy_monitor_handle (monitor_handle);
-	}
+	if (no_live_callbacks (monitor_handle)) {
+		/* if we were waiting for this callback to be dispatched
+		 * to free this monitor, then do it now.
+		 */
+		if (monitor_handle->cancelled)
+			destroy_monitor_handle (monitor_handle);
+		else
+			monitor_handle->pending_timeout = 0;
+	} else
+		/* pending callbacks left, install another timeout */
+		install_timeout (monitor_handle, now);
 
 	G_UNLOCK (handle_hash);
 
@@ -375,9 +380,7 @@
 	GnomeVFSMonitorHandle *monitor_handle;
 	char *uri;
 	time_t now;
-	guint32 delay;
 	GList *l;
-	DispatchData *ddata;
 	
 	g_return_if_fail (info_uri != NULL);
 
@@ -435,26 +438,7 @@
 		monitor_handle->pending_callbacks = 
 			g_list_append(monitor_handle->pending_callbacks, callback_data);
 		
-		delay = get_min_delay (monitor_handle->pending_callbacks, now);
-
-		if (monitor_handle->pending_timeout) {
-			g_source_remove (monitor_handle->pending_timeout);
-		}
-		
-		ddata = g_new (DispatchData, 1);
-		ddata->monitor_handle = monitor_handle;
-		ddata->timeout_count = ++monitor_handle->timeout_count;
-		
-		if (delay == 0) {
-			monitor_handle->pending_timeout = g_idle_add_full (G_PRIORITY_DEFAULT_IDLE,
-									   actually_dispatch_callback,
-									   ddata, (GDestroyNotify)g_free);
-		} else {
-			monitor_handle->pending_timeout = g_timeout_add_full (G_PRIORITY_DEFAULT,
-									      delay * 1000,
-									      actually_dispatch_callback,
-									      ddata, (GDestroyNotify)g_free);
-		}
+		install_timeout (monitor_handle, now);
 	}
 	
 	g_free (uri);
