--- src/journal.c.orig	Sat May  8 12:14:49 2004
+++ src/journal.c	Thu Jul  8 00:23:23 2004
@@ -200,8 +200,10 @@
 
 	/* Don't clobber the file, ask user for permission */
 	GnomeVFSURI *parsed_uri;
+	gboolean exists;
+	GnomeVFSResult    result;
 	parsed_uri = gnome_vfs_uri_new  (filename);
-	gboolean exists = gnome_vfs_uri_exists (parsed_uri);
+	exists = gnome_vfs_uri_exists (parsed_uri);
 	gnome_vfs_uri_unref (parsed_uri);
 	if (exists)
 	{
@@ -217,7 +219,6 @@
 	}
 		
 	/* Try to open the file for writing */
-	GnomeVFSResult    result;
 	result = gnome_vfs_create (&wig->handle, filename, 
 	                     GNOME_VFS_OPEN_WRITE, FALSE, 0644);
 
@@ -392,12 +393,15 @@
 	GttTask *tsk = gtt_interval_get_parent (wig->interval);
 	GttProject *prj = gtt_task_get_parent (tsk);
 	GList *tasks = gtt_project_get_tasks (prj);
+	GList *this_task;
+	GList *prev_task;
+	GttTask *newtask;
 	if (!tasks) return;
-	GList *this_task = g_list_find (tasks, tsk);
+	this_task = g_list_find (tasks, tsk);
 	if (!this_task) return;
-	GList *prev_task = this_task->prev;
+	prev_task = this_task->prev;
 	if (!prev_task) return;
-	GttTask *newtask = prev_task->data;
+	newtask = prev_task->data;
 	gtt_task_append_interval (newtask, wig->interval);
 }
 
@@ -408,12 +412,15 @@
 	GttTask *tsk = gtt_interval_get_parent (wig->interval);
 	GttProject *prj = gtt_task_get_parent (tsk);
 	GList *tasks = gtt_project_get_tasks (prj);
+	GList *this_task;
+	GList *next_task;
+	GttTask *newtask;
 	if (!tasks) return;
-	GList *this_task = g_list_find (tasks, tsk);
+	this_task = g_list_find (tasks, tsk);
 	if (!this_task) return;
-	GList *next_task = this_task->next;
+	next_task = this_task->next;
 	if (!next_task) return;
-	GttTask *newtask = next_task->data;
+	newtask = next_task->data;
 	gtt_task_add_interval (newtask, wig->interval);
 }
 
@@ -461,6 +468,7 @@
 static void
 interval_popup_cb (Wiggy *wig)
 {
+	GttTask *tsk;
 	gtk_menu_popup(GTK_MENU(wig->interval_popup), 
 		NULL, NULL, NULL, wig, 1, 0);
 	if (cutted_task_list)
@@ -494,7 +502,7 @@
 		gtk_widget_set_sensitive (wig->interval_move_down, FALSE);
 	}
 
-	GttTask *tsk = gtt_interval_get_parent(wig->interval);
+	tsk = gtt_interval_get_parent(wig->interval);
 	if (gtt_task_is_first_task (tsk))
 	{
 		gtk_widget_set_sensitive (wig->interval_move_up, FALSE);
@@ -558,6 +566,7 @@
 static void
 task_delete_memo_clicked_cb(GtkWidget * w, gpointer data) 
 {
+	GList * ctl;
 	Wiggy *wig = (Wiggy *) data;
 
 	/* It is physically impossible to cut just the memo, without
@@ -566,7 +575,7 @@
 
 	gtt_task_merge_up (wig->task);
 
-	GList * ctl = g_list_prepend(cutted_task_list, wig->task);
+	ctl = g_list_prepend(cutted_task_list, wig->task);
 	gtt_task_remove (wig->task);
 	cutted_task_list = ctl;
 }
@@ -748,9 +757,10 @@
 on_close_clicked_cb (GtkWidget *w, gpointer data)
 {
 	Wiggy *wig = (Wiggy *) data;
+	GtkWidget *topper;
 
 	if (NULL == wig->top) return;  /* avoid recursive double-free */
-	GtkWidget *topper = wig->top;   /* avoid recursion */
+	topper = wig->top;   /* avoid recursion */
 	wig->top = NULL;
 	gtk_widget_destroy (topper);
 
@@ -838,17 +848,17 @@
 {
 	Wiggy *wig = data;
 	const char * path = gtt_ghtml_resolve_path (url, wig->filepath);
-	if (!path) return;
-
 	GnomeVFSResult    result;
 	GnomeVFSHandle   *vfs;
+#define BSZ 16000
+	char buff[BSZ];
+	GnomeVFSFileSize  bytes_read; 
+	if (!path) return;
+
 	result = gnome_vfs_open (&vfs, path, GNOME_VFS_OPEN_READ);
 
 	if (GNOME_VFS_OK != result) return;
 	
-#define BSZ 16000
-	char buff[BSZ];
-	GnomeVFSFileSize  bytes_read; 
 	result = gnome_vfs_read (vfs, buff, BSZ, &bytes_read);
 	while (GNOME_VFS_OK == result)
 	{
@@ -873,6 +883,7 @@
 {
 	char * str;
 	gpointer addr = NULL;
+	char * msg = _("Left-click to bring up menu");
 
 	/* h4x0r al3rt bare-naked pointer parsing! */
 	str = strstr (url, "0x");
@@ -909,7 +920,6 @@
 		return msg;
 	}
 
-	char * msg = _("Left-click to bring up menu");
 	return g_strdup (msg);
 }
 
@@ -972,8 +982,14 @@
 	/* Create and initialize the hover-help window */
 	if (!wig->hover_help_window)
 	{
+		GtkWidget *label;
+		int px=0, py=0, rx=0, ry=0;
+		GtkWindow *wino;
+		GtkWidget *frame;
+		GtkWidget *align;
+
 		wig->hover_help_window = gtk_window_new(GTK_WINDOW_POPUP);
-		GtkWindow *wino = GTK_WINDOW (wig->hover_help_window);
+		wino = GTK_WINDOW (wig->hover_help_window);
 		gtk_window_set_decorated (wino, FALSE);
 		gtk_window_set_destroy_with_parent (wino, TRUE);
 		gtk_window_set_transient_for (wino, GTK_WINDOW(wig->top));
@@ -981,19 +997,19 @@
 		gtk_window_set_resizable (wino, FALSE);  /* FALSE to enable auto-resize */
 
 		/* There must be a better way to draw a line around the box ?? */
-		GtkWidget *frame = gtk_frame_new (NULL);
+		frame = gtk_frame_new (NULL);
 		gtk_container_add(GTK_CONTAINER(wino), frame);
 		gtk_container_set_resize_mode (GTK_CONTAINER(frame), GTK_RESIZE_PARENT);
 		gtk_widget_show (frame);
 
 		/* There must be a better way to pad the text all around ?? */
-		GtkWidget *align = gtk_alignment_new (0.5, 0.5, 1.0, 1.0);
+		align = gtk_alignment_new (0.5, 0.5, 1.0, 1.0);
 		// gtk_alignment_set_padding (GTK_ALIGNMENT(align), 6, 6, 6, 6);
 		gtk_container_add(GTK_CONTAINER(frame), align);
 		gtk_container_set_resize_mode (GTK_CONTAINER(align), GTK_RESIZE_PARENT);
 		gtk_widget_show (align);
 		
-		GtkWidget *label = gtk_label_new ("xxx");
+		label = gtk_label_new ("xxx");
 		wig->hover_label = GTK_LABEL (label);
 		gtk_container_add(GTK_CONTAINER(align), label);
 		gtk_widget_show (label);
@@ -1002,7 +1018,6 @@
 		gtk_window_set_focus (GTK_WINDOW(wig->top), GTK_WIDGET(wig->html));
 
 		/* Set up in initial default, so later move works. */
-		int px=0, py=0, rx=0, ry=0;
 		gtk_widget_get_pointer (GTK_WIDGET(wig->top), &px, &py);
 		gtk_window_get_position (GTK_WINDOW(wig->top), &rx, &ry);
 		gtk_window_move (wino, rx+px, ry+py);
@@ -1053,25 +1068,28 @@
 perform_form_query (KvpFrame *kvpf)
 {
 	GList *results, *n;
+	char *user_debug;
+	char *query_string;
+	QofSqlQuery *q;
 
 	if (!kvpf) return NULL;
 
 	/* Allow the user to enable form debugging by adding the following html:
 	 * <input type="hidden" name="debug" value="1">
 	 */
-	char *user_debug = kvp_frame_get_string (kvpf, "debug");
+	user_debug = kvp_frame_get_string (kvpf, "debug");
 	if (user_debug)
 	{
 		printf ("Debug: HTML Form Input=%s\n", kvp_frame_to_string (kvpf));
 	}
 
-	QofSqlQuery *q = qof_sql_query_new();
+	q = qof_sql_query_new();
 
 	if (!book) book = qof_book_new();
 	qof_sql_query_set_book (q, book);
 	qof_sql_query_set_kvp (q, kvpf);
 
-	char *query_string = kvp_frame_get_string (kvpf, "query");
+	query_string = kvp_frame_get_string (kvpf, "query");
 	if (!query_string) return NULL;
 	if (0 == query_string[0]) return NULL;
 
