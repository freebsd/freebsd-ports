--- modules/smb-method.c.orig	Tue Jan 11 18:24:53 2005
+++ modules/smb-method.c	Tue Jan 11 18:25:03 2005
@@ -1345,7 +1345,7 @@
 	 GnomeVFSContext *context)
 {
 	FileHandle *handle = (FileHandle *)method_handle;
-	GnomeVFSResult res = GNOME_VFS_OK;;
+	GnomeVFSResult res = GNOME_VFS_OK;
 	SmbAuthContext actx;
 	ssize_t n = 0;
 
