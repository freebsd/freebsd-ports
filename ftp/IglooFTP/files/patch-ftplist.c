--- ftplist.c.orig	Thu Apr 15 19:05:15 1999
+++ ftplist.c	Fri Feb 10 22:53:16 2006
@@ -1158,6 +1158,7 @@
   int this_row = GTK_CLIST (clist)->focus_row;
   char this_path[1024];
   char temp_path[1024];
+  char msg_buf[1024];
   gchar *filename;
   gchar *filesize;
   gchar *filedate;
@@ -1189,6 +1190,14 @@
   IDLE_END;
   CHECK_CONNEXION_VOID;
 
+  /* Is it worth trying to handle this better? */
+
+  if ((strchr(filename, '/') != NULL) || (strstr(filename, "..") != NULL)) {
+  snprintf (msg_buf, sizeof(msg_buf), "Skipping non-relative filename: %s", filename);
+    error_message (msg_buf);
+    return;
+  }
+
   if (IGLOO_download (filename, filesize, filedate, NULL))
     {
       char that_path[1024];
@@ -1255,6 +1264,7 @@
 static void
 perfom_recursive_command_on_selection (char recursive_command, char *optionnal_arg, char IS_TOP_DIR)
 {
+  int fd = -1;
   GList *selection = GTK_CLIST (clist)->selection;
   gchar *filename;
   gchar *fileperm;
@@ -1265,9 +1275,17 @@
   char DIR_FOUND_IN_SELECTION = FALSE;
   char *current_remote_dir = strdup (this_session.cwd_dir);
 
-  tmpnam (tmp_filename);
-  tmp = fopen (tmp_filename, "w");
+  sprintf(tmp_filename, tmpfile_template);
 
+  if ((fd = mkstemp (tmp_filename)) == -1 || (tmp = fdopen (fd, "w")) == NULL)
+  {
+    if (fd != -1) {
+      unlink(tmp_filename);
+      close(fd);
+    }
+    DEBUG("Unable to create temporary file.");
+    return;
+  }
 
   while (selection && (!want_abort))
     {
@@ -1710,6 +1728,7 @@
 static char
 download_selection_recursive (void)
 {
+  int fd = -1;
   GdkColor done_color = GREYCYAN;
   GdkColormap *colormap;
   GList *selection = GTK_CLIST (clist)->selection;
@@ -1725,10 +1744,19 @@
   char *current_remote_dir = strdup (this_session.cwd_dir);
   char current_local_dir[1024];
 
+  sprintf(tmp_filename, tmpfile_template);
+
   getcwd (current_local_dir, sizeof (current_local_dir));
 
-  tmpnam (tmp_filename);
-  tmp = fopen (tmp_filename, "w");
+  if ((fd = mkstemp (tmp_filename)) == -1 || (tmp = fdopen (fd, "w")) == NULL)
+  {
+    if (fd != -1) {
+      unlink(tmp_filename);
+      close(fd);
+    }
+    DEBUG("Unable to create temporary file.");
+    return FALSE;
+  }
 
   colormap = gtk_widget_get_colormap (window);
   gdk_color_alloc (colormap, &done_color);
@@ -1736,6 +1764,7 @@
   while (selection && (!xfer_abort) && (!want_abort))
     {
       static GtkStyle *cell_style;
+      char msg_buf[1024];
       index = (int) selection->data;
 
       cell_style = gtk_clist_get_cell_style (GTK_CLIST (clist), index, 3);
@@ -1748,6 +1777,17 @@
       gtk_clist_get_text (GTK_CLIST (clist), index, 2, &filesize);
       gtk_clist_get_text (GTK_CLIST (clist), index, 3, &filedate);
       gtk_clist_get_text (GTK_CLIST (clist), index, 4, &fileperm);
+
+      /* Basic sanity checks */
+
+      if ((strchr(filename, '/') != NULL) || (strstr(filename, "..") != NULL)) {
+        snprintf (msg_buf, sizeof(msg_buf), "Skipping non-relative filename: %s", filename);
+        error_message (msg_buf);
+        selection = selection->next;
+        gtk_clist_unselect_row (GTK_CLIST (clist), index, 0);
+        gtk_clist_moveto (GTK_CLIST (clist), index, 0, 0.5, 0);
+        continue;
+      }
 
       if (fileperm[0] != 'd')
 	{
