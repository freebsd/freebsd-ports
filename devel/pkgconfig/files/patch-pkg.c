
$FreeBSD$

--- pkg.c.orig	Wed Jan  3 11:34:49 2001
+++ pkg.c	Tue May 15 11:48:04 2001
@@ -40,7 +40,7 @@
  * locations, ignoring duplicates
  */
 static void
-scan_dir (const char *dirname)
+scan_dir (const char *dirname, void *quiet)
 {
   DIR *dir = opendir (dirname);
   struct dirent *dent;
@@ -51,8 +51,9 @@
 
   if (!dir)
     {
-      fprintf (stderr, "Warning: cannot open directory '%s' in package search path: %s\n",
-               dirname, g_strerror (errno));
+      if (!quiet)
+        fprintf (stderr, "Warning: cannot open directory '%s' in package search path: %s\n",
+                 dirname, g_strerror (errno));
       return;
     }
 
@@ -96,7 +97,9 @@
       locations = g_hash_table_new (g_str_hash, g_str_equal);
       
       g_slist_foreach (search_dirs, (GFunc)scan_dir, NULL);
-      scan_dir (PKGLIBDIR);
+      scan_dir (PKGLIBDIR, (void *)0);
+      scan_dir (XPKGLIBDIR, (void *)1);
+      scan_dir (LPKGLIBDIR, (void *)1);
     }
 }
 
