--- libgnomevfs/gnome-vfs-process.c.orig	Mon Jul 16 20:21:07 2001
+++ libgnomevfs/gnome-vfs-process.c	Sat Aug 14 00:13:06 2004
@@ -258,7 +258,7 @@
  * 
  * Return value: A numeric value reporting the result of the operation.
  **/
-GnomeVFSProcessRunResult
+GnomeVFSProcessResult
 gnome_vfs_process_signal (GnomeVFSProcess *process,
 			  guint signal_number)
 {
