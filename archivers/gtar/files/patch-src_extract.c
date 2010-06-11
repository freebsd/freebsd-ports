$FreeBSD$
http://git.savannah.gnu.org/cgit/tar.git/commit/?id=b60e56fdb6fd8d82a1f92a4fa7781d9a3184dce1

--- src/extract.c.orig	2010-01-26 12:28:09.000000000 +0100
+++ src/extract.c	2010-06-11 20:54:04.000000000 +0200
@@ -888,12 +888,22 @@ create_placeholder_file (char *file_name
   struct stat st;
 
   while ((fd = open (file_name, O_WRONLY | O_CREAT | O_EXCL, 0)) < 0)
-    if (! maybe_recoverable (file_name, interdir_made))
-      break;
+    {
+      switch (maybe_recoverable (file_name, interdir_made))
+	{
+	case RECOVER_OK:
+	  continue;
+	  
+	case RECOVER_SKIP:
+	  return 0;
+	  
+	case RECOVER_NO:
+	  open_error (file_name);
+	  return -1;
+	}
+      }
 
-  if (fd < 0)
-    open_error (file_name);
-  else if (fstat (fd, &st) != 0)
+  if (fstat (fd, &st) != 0)
     {
       stat_error (file_name);
       close (fd);
@@ -956,7 +966,8 @@ extract_link (char *file_name, int typef
 {
   int interdir_made = 0;
   char const *link_name;
-
+  int rc;
+  
   link_name = current_stat_info.link_name;
   
   if (! absolute_names_option && contains_dot_dot (link_name))
@@ -996,8 +1007,10 @@ extract_link (char *file_name, int typef
 
       errno = e;
     }
-  while (maybe_recoverable (file_name, &interdir_made));
+  while ((rc = maybe_recoverable (file_name, &interdir_made)) == RECOVER_OK);
 
+  if (rc == RECOVER_SKIP)
+    return 0;
   if (!(incremental_option && errno == EEXIST))
     {
       link_error (link_name, file_name);
@@ -1010,7 +1023,6 @@ static int
 extract_symlink (char *file_name, int typeflag)
 {
 #ifdef HAVE_SYMLINK
-  int status;
   int interdir_made = 0;
 
   if (! absolute_names_option
@@ -1018,15 +1030,22 @@ extract_symlink (char *file_name, int ty
 	  || contains_dot_dot (current_stat_info.link_name)))
     return create_placeholder_file (file_name, true, &interdir_made);
 
-  while ((status = symlink (current_stat_info.link_name, file_name)))
-    if (!maybe_recoverable (file_name, &interdir_made))
-      break;
-
-  if (status == 0)
-    set_stat (file_name, &current_stat_info, NULL, 0, 0, SYMTYPE);
-  else
-    symlink_error (current_stat_info.link_name, file_name);
-  return status;
+  while (symlink (current_stat_info.link_name, file_name))
+    switch (maybe_recoverable (file_name, &interdir_made))
+      {
+      case RECOVER_OK:
+	continue;
+	
+      case RECOVER_SKIP:
+	return 0;
+	
+      case RECOVER_NO:
+	symlink_error (current_stat_info.link_name, file_name);
+	return -1;
+      }
+  
+  set_stat (file_name, &current_stat_info, NULL, 0, 0, SYMTYPE);
+  return 0;
 
 #else
   static int warned_once;
@@ -1052,16 +1071,23 @@ extract_node (char *file_name, int typef
   mode_t invert_permissions =
     0 < same_owner_option ? mode & (S_IRWXG | S_IRWXO) : 0;
 
-  do
-    status = mknod (file_name, mode ^ invert_permissions,
-		    current_stat_info.stat.st_rdev);
-  while (status && maybe_recoverable (file_name, &interdir_made));
+  while (mknod (file_name, mode ^ invert_permissions,
+		current_stat_info.stat.st_rdev))
+    switch (maybe_recoverable (file_name, &interdir_made))
+      {
+      case RECOVER_OK:
+	continue;
+	
+      case RECOVER_SKIP:
+	return 0;
+	
+      case RECOVER_NO:
+	mknod_error (file_name);
+	return -1;
+      }
 
-  if (status != 0)
-    mknod_error (file_name);
-  else
-    set_stat (file_name, &current_stat_info, NULL, invert_permissions,
-	      ARCHIVED_PERMSTATUS, typeflag);
+  set_stat (file_name, &current_stat_info, NULL, invert_permissions,
+	    ARCHIVED_PERMSTATUS, typeflag);
   return status;
 }
 #endif
@@ -1077,15 +1103,22 @@ extract_fifo (char *file_name, int typef
     0 < same_owner_option ? mode & (S_IRWXG | S_IRWXO) : 0;
 
   while ((status = mkfifo (file_name, mode)) != 0)
-    if (!maybe_recoverable (file_name, &interdir_made))
-      break;
+    switch (maybe_recoverable (file_name, &interdir_made))
+      {
+      case RECOVER_OK:
+	continue;
+	
+      case RECOVER_SKIP:
+	return 0;
+	
+      case RECOVER_NO:
+	mkfifo_error (file_name);
+	return -1;
+      }
 
-  if (status == 0)
-    set_stat (file_name, &current_stat_info, NULL, invert_permissions,
-	      ARCHIVED_PERMSTATUS, typeflag);
-  else
-    mkfifo_error (file_name);
-  return status;
+  set_stat (file_name, &current_stat_info, NULL, invert_permissions,
+	    ARCHIVED_PERMSTATUS, typeflag);
+  return 0;
 }
 #endif
 
