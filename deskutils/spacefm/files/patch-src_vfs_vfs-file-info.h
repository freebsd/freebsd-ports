--- src/vfs/vfs-file-info.h.orig	2023-02-20 22:01:54 UTC
+++ src/vfs/vfs-file-info.h
@@ -56,7 +56,7 @@ struct _VFSFileInfo
     time_t mtime;
     time_t atime;
     long blksize;  //sfm was long then blksize_t but blksize_t not defined for squeeze gcc
-    blkcnt64_t blocks;      //sfm was blkcnt_t
+    blkcnt_t blocks;      //sfm was blkcnt_t
 
     char* name; /* real name on file system */
     char* disp_name;  /* displayed name (in UTF-8) */
