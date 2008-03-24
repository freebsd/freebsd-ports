--- gio/glocalfile.c.orig	2008-03-10 23:04:57.000000000 -0400
+++ gio/glocalfile.c	2008-03-10 23:05:23.000000000 -0400
@@ -1001,7 +1001,7 @@ g_local_file_query_filesystem_info (GFil
 #endif
     }
 #ifdef USE_STATFS
-#if defined(HAVE_STRUCT_STATFS_FS_TYPENAME)
+#if defined(HAVE_STRUCT_STATFS_F_FSTYPENAME)
   fstype = g_strdup(statfs_buffer.f_fstypename);
 #else
   fstype = get_fs_type (statfs_buffer.f_type);
