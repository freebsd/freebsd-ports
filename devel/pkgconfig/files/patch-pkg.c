
$FreeBSD$

--- pkg.c.orig	Mon May 28 16:02:53 2001
+++ pkg.c	Wed Jul 11 14:42:22 2001
@@ -71,7 +71,7 @@
  * locations, ignoring duplicates
  */
 static void
-scan_dir (const char *dirname)
+scan_dir (const char *dirname, void *quiet)
 {
   DIR *dir = opendir (dirname);
   struct dirent *dent;
@@ -82,7 +82,8 @@
 
   if (!dir)
     {
-      debug_spew ("Cannot open directory '%s' in package search path: %s\n",
+      if (!quiet)
+          debug_spew ("Cannot open directory '%s' in package search path: %s\n",
                   dirname, g_strerror (errno));
       return;
     }
@@ -141,7 +142,9 @@
       locations = g_hash_table_new (g_str_hash, g_str_equal);
       
       g_slist_foreach (search_dirs, (GFunc)scan_dir, NULL);
-      scan_dir (PKGLIBDIR);
+      scan_dir (PKGLIBDIR, (void *)0);
+      scan_dir (XPKGLIBDIR, (void *)1);
+      scan_dir (LPKGLIBDIR, (void *)1);
     }
 }
 
