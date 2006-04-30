--- logview/logrtns.c.orig	Wed Apr 19 00:28:00 2006
+++ logview/logrtns.c	Wed Apr 19 00:29:24 2006
@@ -48,7 +48,7 @@ file_exist (char *filename, gboolean sho
    char *secondary = NULL;
 
    if (filename == NULL)
-       return;
+       return FALSE;
 
    result = gnome_vfs_open (&handle, filename, GNOME_VFS_OPEN_READ);
    if (result != GNOME_VFS_OK) {
@@ -83,7 +83,7 @@ file_is_zipped (char *filename)
 	char *mime_type;
 
     if (filename == NULL)
-        return;
+        return FALSE;
 
 	mime_type = gnome_vfs_get_mime_type (filename);
     if (mime_type == NULL)
@@ -106,7 +106,7 @@ file_is_log (char *filename, gboolean sh
     LogStats *stats;
 
     if (filename == NULL)
-        return;
+        return FALSE;
 
     stats = log_stats_new (filename, show_error);
     if (stats==NULL)
@@ -134,11 +134,11 @@ string_get_date_string (gchar *line)
     int i=0;
 
     if (line == NULL || line[0] == 0)
-        return;
+        return NULL;
 
     split = g_strsplit (line, " ", 4);
     if (split == NULL)
-        return;
+        return NULL;
 
     while ((day == NULL || month == NULL) && split[i]!=NULL && i<4) {
         if (g_str_equal (split[i], "")) {
@@ -531,7 +531,7 @@ log_unbold (gpointer data)
     LogList *list;
     Log *log = data;
 
-    g_return_if_fail (log != NULL);
+    g_return_val_if_fail (log != NULL, FALSE);
 
     logview = log->window;
 
