--- modules/bzip2-method.c.orig	Wed Apr 13 21:58:54 2005
+++ modules/bzip2-method.c	Mon Nov 28 15:09:59 2005
@@ -435,7 +435,7 @@
 
 	if (bzip2_handle->last_bz_result != BZ_OK) {
 		if (bzip2_handle->last_bz_result == BZ_STREAM_END)
-			return GNOME_VFS_OK;
+			return GNOME_VFS_ERROR_EOF;
 		else
 			return result_from_bz_result (bzip2_handle->last_bz_result);
 	} else if (bzip2_handle->last_vfs_result != GNOME_VFS_OK) {
