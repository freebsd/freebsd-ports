--- src/copyin.c.orig	2015-09-12 10:57:30 UTC
+++ src/copyin.c
@@ -695,6 +695,51 @@ copyin_link (struct cpio_file_stat *file
   free (link_name);
 }
 
+
+static int
+path_contains_symlink(char *path)
+{
+  struct stat st;
+  char *slash;
+  char *nextslash;
+
+  /* we got NULL pointer or empty string */
+  if (!path || !*path) {
+    return false;
+  }
+
+  slash = path;
+
+  while ((nextslash = strchr(slash + 1, '/')) != NULL) {
+    slash = nextslash;
+    *slash = '\0';
+
+    if (lstat(path, &st) != 0) {
+      if (errno == ELOOP) {
+        /* ELOOP - too many symlinks */
+        *slash = '/';
+        return true;
+      } else if (errno == ENOMEM) {
+        /* No memory for lstat - terminate */
+        xalloc_die();
+      } else {
+        /* cannot lstat path - give up */
+        *slash = '/';
+        return false;
+      }
+    }
+
+    if (S_ISLNK(st.st_mode)) {
+      *slash = '/';
+      return true;
+    }
+
+    *slash = '/';
+  }
+
+  return false;
+}
+
 static void
 copyin_file (struct cpio_file_stat *file_hdr, int in_file_des)
 {
@@ -1468,6 +1513,23 @@ process_copy_in ()
 	{
 	  /* Copy the input file into the directory structure.  */
 
+          /* Can we write files over symlinks? */
+          if (!extract_over_symlinks)
+            {
+              if (path_contains_symlink(file_hdr.c_name))
+                {
+                  /* skip the file */
+                  /*
+                  fprintf(stderr, "Can't write over symlinks. Skipping %s\n", file_hdr.c_name);
+                  tape_toss_input (in_file_des, file_hdr.c_filesize);
+                  tape_skip_padding (in_file_des, file_hdr.c_filesize);
+                  continue;
+                  */
+                  /* terminate */
+	          error (PAXEXIT_FAILURE, 0, _("Can't write over symlinks: %s\n"), file_hdr.c_name);
+                }
+            }
+
 	  /* Do we need to rename the file? */
 	  if (rename_flag || rename_batch_file)
 	    {
