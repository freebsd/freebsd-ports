--- libgnomevfs/gnome-vfs-resolve.c.orig	Sat Jul 31 17:52:23 2004
+++ libgnomevfs/gnome-vfs-resolve.c	Sat Jul 31 17:52:45 2004
@@ -171,8 +171,10 @@
 	   switch (error) {
 			 
 	   case EAI_NONAME: return GNOME_VFS_ERROR_HOST_NOT_FOUND;
+#if defined(EAI_ADDRFAMILY) && defined(EAI_NODATA)
 	   case EAI_ADDRFAMILY:		
 	   case EAI_NODATA: return GNOME_VFS_ERROR_HOST_HAS_NO_ADDRESS;
+#endif
 	   case EAI_SYSTEM: return gnome_vfs_result_from_errno ();
 	   case EAI_FAIL:
 	   case EAI_AGAIN: return GNOME_VFS_ERROR_NAMESERVER;
