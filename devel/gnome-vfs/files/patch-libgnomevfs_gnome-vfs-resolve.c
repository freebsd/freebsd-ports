--- libgnomevfs/gnome-vfs-resolve.c.orig	Tue Apr 19 07:54:52 2005
+++ libgnomevfs/gnome-vfs-resolve.c	Sun May 22 23:25:22 2005
@@ -171,10 +171,12 @@ _gnome_vfs_result_from_gai_error (int er
 	   switch (error) {
 			 
 	   case EAI_NONAME: return GNOME_VFS_ERROR_HOST_NOT_FOUND;
+#ifdef EAI_NODATA
 #ifdef EAI_ADDRFAMILY
 	   case EAI_ADDRFAMILY:		
 #endif
 	   case EAI_NODATA: return GNOME_VFS_ERROR_HOST_HAS_NO_ADDRESS;
+#endif
 #ifdef EAI_SYSTEM
 	   case EAI_SYSTEM: return gnome_vfs_result_from_errno ();
 #endif
