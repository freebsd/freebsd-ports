--- pkg.c.orig	Thu Jan 16 16:07:09 2003
+++ pkg.c	Wed Jan 22 18:11:41 2003
@@ -113,7 +113,7 @@
  * locations, ignoring duplicates
  */
 static void
-scan_dir (const char *dirname)
+scan_dir (const char *dirname, void *quiet)
 {
   DIR *dir;
   struct dirent *dent;
@@ -133,7 +133,8 @@
   free (dirname_copy);
   if (!dir)
     {
-      debug_spew ("Cannot open directory '%s' in package search path: %s\n",
+      if (!quiet)
+          debug_spew ("Cannot open directory '%s' in package search path: %s\n",
                   dirname, g_strerror (errno));
       return;
     }
@@ -202,7 +203,9 @@
       path_positions = g_hash_table_new (g_str_hash, g_str_equal);
       
       g_slist_foreach (search_dirs, (GFunc)scan_dir, NULL);
-      scan_dir (pkglibdir);
+      scan_dir (pkglibdir, (void *)0);
+      scan_dir (XPKGLIBDIR, (void *)1);
+      scan_dir (LPKGLIBDIR, (void *)1);
     }
 }
 
