--- libwzd-core/wzd_list.c.orig	2023-02-11 11:22:20 UTC
+++ libwzd-core/wzd_list.c
@@ -277,7 +277,7 @@ char * mlst_single_file(const char *filename, wzd_cont
 
   ptr = strrchr(filename,'/');
   if (!ptr) return NULL;
-  if (ptr+1 != '\0') ptr++;
+  if (ptr[1] != '\0') ptr++;
 
   /** \bug this kills VFS */
 /*  if (fs_file_lstat(filename,&s)) return -1;*/
