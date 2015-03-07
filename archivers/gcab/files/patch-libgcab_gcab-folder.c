From 0ccdf564b6a3e26522a8eb1858f1828844fa3536 Mon Sep 17 00:00:00 2001
From: Stephen Kitt <steve@sk2.org>
Date: Mon, 5 Jan 2015 06:28:00 +0000
Subject: Avoid path traversal

gcab suffers from a directory traversal bug: it doesn't filter leading
slashes from paths in CAB files.
(see https://bugs.debian.org/774580)

The attached patch fixes this, at the cost of ugly paths when faced with
relative traversals. At least all the CAB's contents can be extracted,
without overwriting anything outside the extraction path.

https://bugzilla.gnome.org/show_bug.cgi?id=742331

diff --git a/libgcab/gcab-folder.c b/libgcab/gcab-folder.c
index a140e2c..9510cf3 100644
--- libgcab/gcab-folder.c
+++ libgcab/gcab-folder.c
@@ -362,9 +362,25 @@ gcab_folder_extract (GCabFolder *self,
                 fname[i] = '/';
 
         GFile *gfile = g_file_resolve_relative_path (path, fname);
-        GFile *parent = g_file_get_parent (gfile);
         g_free (fname);
 
+        if (!g_file_has_prefix (gfile, path)) {
+            // "Rebase" the file in the given path, to ensure we never escape it
+            char *rawpath = g_file_get_path (gfile);
+            if (rawpath != NULL) {
+                char *newpath = rawpath;
+                while (*newpath != 0 && *newpath == G_DIR_SEPARATOR) {
+                    newpath++;
+                }
+                GFile *newgfile = g_file_resolve_relative_path (path, newpath);
+                g_free (rawpath);
+                g_object_unref (gfile);
+                gfile = newgfile;
+            }
+        }
+
+        GFile *parent = g_file_get_parent (gfile);
+
         if (!g_file_make_directory_with_parents (parent, cancellable, &my_error)) {
             if (g_error_matches (my_error, G_IO_ERROR, G_IO_ERROR_EXISTS))
                 g_clear_error (&my_error);
-- 
cgit v0.10.2

