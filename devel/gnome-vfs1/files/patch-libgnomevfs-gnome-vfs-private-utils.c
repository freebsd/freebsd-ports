--- libgnomevfs/gnome-vfs-private-utils.c.orig	Mon Jul 16 20:21:07 2001
+++ libgnomevfs/gnome-vfs-private-utils.c	Sat Aug 14 00:00:56 2004
@@ -263,7 +263,7 @@
  * 
  * Return value: 
  **/
-GnomeVFSProcessResult
+GnomeVFSProcessRunResult
 gnome_vfs_process_run_cancellable (const gchar *file_name,
 				   const gchar * const argv[],
 				   GnomeVFSProcessOptions options,
