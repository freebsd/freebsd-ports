--- pkg.c.orig	Tue Apr 12 07:08:13 2005
+++ pkg.c	Tue Apr 12 13:55:42 2005
@@ -128,7 +128,7 @@ name_ends_in_uninstalled (const char *st
  * locations, ignoring duplicates
  */
 static void
-scan_dir (const char *dirname)
+scan_dir (const char *dirname, void *quiet)
 {
   DIR *dir;
   struct dirent *dent;
@@ -148,7 +148,8 @@ scan_dir (const char *dirname)
   free (dirname_copy);
   if (!dir)
     {
-      debug_spew ("Cannot open directory '%s' in package search path: %s\n",
+      if (!quiet)
+        debug_spew ("Cannot open directory '%s' in package search path: %s\n",
                   dirname, g_strerror (errno));
       return;
     }
