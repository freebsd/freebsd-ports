--- libgnomevfs/gnome-vfs-unix-mounts.c.orig	Mon Mar  8 22:29:57 2004
+++ libgnomevfs/gnome-vfs-unix-mounts.c	Mon Mar  8 22:33:35 2004
@@ -857,8 +857,9 @@
 
 #ifdef HAVE_SYS_SYSCTL_H
 		if (usermnt != 0) {
+			uid_t uid = getuid ();
 			if (stat (fstab->fs_file, &sb) == 0) {
-				if (sb.st_uid != 0) {
+				if (uid == 0 || sb.st_uid == uid) {
 					mount_entry->is_user_mountable = TRUE;
 				}
 			}
