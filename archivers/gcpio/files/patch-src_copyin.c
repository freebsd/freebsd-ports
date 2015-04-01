--- src/copyin.c.orig	2010-02-15 10:02:23 UTC
+++ src/copyin.c
@@ -124,10 +124,30 @@ tape_skip_padding (int in_file_des, off_
   if (pad != 0)
     tape_toss_input (in_file_des, pad);
 }
-
+
+static char *
+get_link_name (struct cpio_file_stat *file_hdr, int in_file_des)
+{
+  char *link_name;
+  
+  if (file_hdr->c_filesize < 0 || file_hdr->c_filesize > SIZE_MAX-1)
+    {
+      error (0, 0, _("%s: stored filename length is out of range"),
+	     file_hdr->c_name);
+      link_name = NULL;
+    }
+  else
+    {
+      link_name = xmalloc (file_hdr->c_filesize + 1);
+      tape_buffered_read (link_name, in_file_des, file_hdr->c_filesize);
+      link_name[file_hdr->c_filesize] = '\0';
+      tape_skip_padding (in_file_des, file_hdr->c_filesize);
+    }
+  return link_name;
+}
 
 static void
-list_file(struct cpio_file_stat* file_hdr, int in_file_des)
+list_file (struct cpio_file_stat* file_hdr, int in_file_des)
 {
   if (verbose_flag)
     {
@@ -136,21 +156,16 @@ list_file(struct cpio_file_stat* file_hd
 	{
 	  if (archive_format != arf_tar && archive_format != arf_ustar)
 	    {
-	      char *link_name = NULL;	/* Name of hard and symbolic links.  */
-
-	      link_name = (char *) xmalloc ((unsigned int) file_hdr->c_filesize + 1);
-	      link_name[file_hdr->c_filesize] = '\0';
-	      tape_buffered_read (link_name, in_file_des, file_hdr->c_filesize);
-	      long_format (file_hdr, link_name);
-	      free (link_name);
-	      tape_skip_padding (in_file_des, file_hdr->c_filesize);
-	      return;
+	      char *link_name = get_link_name (file_hdr, in_file_des);
+	      if (link_name)
+		{
+		  long_format (file_hdr, link_name);
+		  free (link_name);
+		}
 	    }
 	  else
-	    {
-	      long_format (file_hdr, file_hdr->c_tar_linkname);
-	      return;
-	    }
+	    long_format (file_hdr, file_hdr->c_tar_linkname);
+	  return;
 	}
       else
 #endif
@@ -640,7 +655,7 @@ copyin_device (struct cpio_file_stat* fi
 }
 
 static void
-copyin_link(struct cpio_file_stat *file_hdr, int in_file_des)
+copyin_link (struct cpio_file_stat *file_hdr, int in_file_des)
 {
   char *link_name = NULL;	/* Name of hard and symbolic links.  */
   int res;			/* Result of various function calls.  */
@@ -650,10 +665,9 @@ copyin_link(struct cpio_file_stat *file_
 
   if (archive_format != arf_tar && archive_format != arf_ustar)
     {
-      link_name = (char *) xmalloc ((unsigned int) file_hdr->c_filesize + 1);
-      link_name[file_hdr->c_filesize] = '\0';
-      tape_buffered_read (link_name, in_file_des, file_hdr->c_filesize);
-      tape_skip_padding (in_file_des, file_hdr->c_filesize);
+      link_name = get_link_name (file_hdr, in_file_des);
+      if (!link_name)
+	return;
     }
   else
     {
@@ -686,6 +700,51 @@ copyin_link(struct cpio_file_stat *file_
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
@@ -1005,7 +1064,7 @@ read_in_header (struct cpio_file_stat *f
 
   file_hdr->c_tar_linkname = NULL;
 
-  tape_buffered_read (magic.str, in_des, 6L);
+  tape_buffered_read (magic.str, in_des, sizeof (magic.str));
   while (1)
     {
       if (append_flag)
@@ -1050,8 +1109,8 @@ read_in_header (struct cpio_file_stat *f
 	  break;
 	}
       bytes_skipped++;
-      memmove (magic.str, magic.str + 1, 5);
-      tape_buffered_read (magic.str, in_des, 1L);
+      memmove (magic.str, magic.str + 1, sizeof (magic.str) - 1);
+      tape_buffered_read (magic.str + sizeof (magic.str) - 1, in_des, 1L);
     }
 }
 
@@ -1457,6 +1516,23 @@ process_copy_in ()
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
+	          error (1, 0, _("Can't write over symlinks: %s\n"), file_hdr.c_name);
+                }
+            }
+
 	  /* Do we need to rename the file? */
 	  if (rename_flag || rename_batch_file)
 	    {
