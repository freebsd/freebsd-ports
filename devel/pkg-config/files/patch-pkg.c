--- pkg.c.orig	Thu Feb  7 14:32:13 2002
+++ pkg.c	Tue Mar 12 16:54:50 2002
@@ -93,7 +93,7 @@
  * locations, ignoring duplicates
  */
 static void
-scan_dir (const char *dirname)
+scan_dir (const char *dirname, void *quiet)
 {
   DIR *dir;
   struct dirent *dent;
@@ -113,7 +113,8 @@
   free (dirname_copy);
   if (!dir)
     {
-      debug_spew ("Cannot open directory '%s' in package search path: %s\n",
+      if (!quiet)
+          debug_spew ("Cannot open directory '%s' in package search path: %s\n",
                   dirname, g_strerror (errno));
       return;
     }
@@ -177,7 +178,9 @@
       path_positions = g_hash_table_new (g_str_hash, g_str_equal);
       
       g_slist_foreach (search_dirs, (GFunc)scan_dir, NULL);
-      scan_dir (PKGLIBDIR);
+      scan_dir (PKGLIBDIR, (void *)0);
+      scan_dir (XPKGLIBDIR, (void *)1);
+      scan_dir (LPKGLIBDIR, (void *)1);
     }
 }
