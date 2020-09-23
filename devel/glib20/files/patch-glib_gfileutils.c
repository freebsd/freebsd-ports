https://gitlab.gnome.org/GNOME/glib/merge_requests/832

Index: glib/gfileutils.c
--- glib/gfileutils.c.orig
+++ glib/gfileutils.c
@@ -259,7 +259,7 @@ g_mkdir_with_parents (const gchar *pathname,
       
       if (!g_file_test (fn, G_FILE_TEST_EXISTS))
 	{
-	  if (g_mkdir (fn, mode) == -1 && errno != EEXIST)
+	  if (g_mkdir (fn, mode) == -1 && errno != EEXIST && (p ? (errno != ENOENT) : (-1)))
 	    {
 	      int errno_save = errno;
 	      if (errno != ENOENT || !p)
