--- src/gcompris/gameutil.c.orig	2010-03-21 17:02:26.000000000 -0400
+++ src/gcompris/gameutil.c	2010-03-21 17:03:23.000000000 -0400
@@ -568,6 +568,7 @@ gc_file_find_absolute(const gchar *forma
   int			 i = 0;
   gchar			*filename;
   gchar			*absolute_filename;
+  gchar                         rpath[PATH_MAX];
   gchar			*dir_to_search[4];
   GcomprisProperties	*properties = gc_prop_get();
 
@@ -654,7 +655,7 @@ gc_file_find_absolute(const gchar *forma
 
  FOUND:
   g_free(filename);
-  char *abs_name = realpath(absolute_filename, NULL);
+  char *abs_name = g_strdup (realpath(absolute_filename, rpath));
   g_free(absolute_filename);
   return abs_name;
 }
