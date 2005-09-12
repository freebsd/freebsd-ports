--- modules/smb-method.c.orig	Wed Mar  2 18:44:11 2005
+++ modules/smb-method.c	Mon Sep 12 02:36:28 2005
@@ -1425,7 +1425,7 @@ do_close (GnomeVFSMethod *method,
 
 		/* Important: perform_authentication leaves and re-enters the lock! */
 		while (perform_authentication (&actx) > 0) {
-			r = smb_context->close (smb_context, handle->file);
+			r = smb_context->close_fn (smb_context, handle->file);
 			actx.res = (r >= 0) ? GNOME_VFS_OK : gnome_vfs_result_from_errno ();
 		}
 
@@ -1446,7 +1446,7 @@ do_read (GnomeVFSMethod *method,
 	 GnomeVFSContext *context)
 {
 	FileHandle *handle = (FileHandle *)method_handle;
-	GnomeVFSResult res = GNOME_VFS_OK;;
+	GnomeVFSResult res = GNOME_VFS_OK;
 	SmbAuthContext actx;
 	ssize_t n = 0;
 
