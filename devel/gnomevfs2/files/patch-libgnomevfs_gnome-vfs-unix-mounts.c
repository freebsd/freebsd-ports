--- libgnomevfs/gnome-vfs-unix-mounts.c.orig	Mon Feb 16 06:13:27 2004
+++ libgnomevfs/gnome-vfs-unix-mounts.c	Sat Apr 17 00:45:01 2004
@@ -141,9 +141,9 @@
 		FD_ZERO(&read_fds);
 		FD_SET(pipes[0], &read_fds);
 
-		/* Wait max half a second */
-		tv.tv_sec = 0;
-		tv.tv_usec = 500;
+		/* Wait max one second */
+		tv.tv_sec = 1;
+		tv.tv_usec = 0;
 
 		res = select(pipes[0] + 1,
 			     &read_fds, NULL, NULL, &tv);
@@ -428,7 +428,7 @@
 		mount_entry->mount_path = g_strdup (mntent[i].f_mntonname);
 		mount_entry->device_path = g_strdup (mntent[i].f_mntfromname);
 		mount_entry->filesystem_type = g_strdup (mntent[i].f_fstypename);
-		if (mntent[i].f_flags == MNT_RDONLY) {
+		if (mntent[i].f_flags & MNT_RDONLY) {
 		    	mount_entry->is_read_only = TRUE;
 		}
 
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
