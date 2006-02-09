--- server/gam_fs.c.orig	Sat Aug  6 00:31:46 2005
+++ server/gam_fs.c	Wed Feb  8 15:05:24 2006
@@ -7,6 +7,11 @@
 #include <string.h>
 #include <errno.h>
 #include <glib.h>
+#ifdef __FreeBSD__
+#include <sys/param.h>
+#include <sys/ucred.h>
+#include <sys/mount.h>
+#endif
 #include "gam_error.h"
 #include "gam_fs.h"
 
@@ -26,7 +31,9 @@
 static gboolean initialized = FALSE;
 static GList *filesystems = NULL;
 static GList *fs_props = NULL;
+#ifdef __linux__
 static struct stat mtab_sbuf;
+#endif
 
 static void
 gam_fs_free_filesystems (void)
@@ -110,6 +117,7 @@
 	return strlen(fsb->path) - strlen (fsa->path);
 }
 
+#ifdef __linux__
 static void
 gam_fs_scan_mtab (void)
 {
@@ -165,10 +173,40 @@
 	gam_fs_free_filesystems ();
 	filesystems = g_list_sort (new_filesystems, gam_fs_filesystem_sort_cb);
 }
+#endif
+
+#ifdef __FreeBSD__
+static void
+gam_fs_getmntinfo (void)
+{
+	struct statfs *stat;
+	GList *new_filesystems = NULL;
+	gam_fs *fs = NULL;
+        int i, n;
+
+	n = getmntinfo(&stat, MNT_NOWAIT);
+	if (n == -1)
+		return;
+
+	for (i = 0; i < n; i++)
+	{
+		fs = g_new0 (gam_fs, 1);
+		fs->path = g_strdup (stat[i].f_mntonname);
+		fs->fsname = g_strdup (stat[i].f_fstypename);
+
+		new_filesystems = g_list_prepend (new_filesystems, fs);
+	}
+
+        /* Replace the old file systems list with the new one */
+        gam_fs_free_filesystems ();
+        filesystems = g_list_sort (new_filesystems, gam_fs_filesystem_sort_cb);
+}
+#endif
 
 void
 gam_fs_init (void)
 {
+#if defined(__linux__)
 	if (initialized == FALSE)
 	{
 		initialized = TRUE;
@@ -181,6 +219,7 @@
 		if (stat("/etc/mtab", &mtab_sbuf) != 0)
 		{
 			GAM_DEBUG(DEBUG_INFO, "Could not stat /etc/mtab\n");
+                        return;
 		}
 		gam_fs_scan_mtab ();
 	} else {
@@ -189,6 +228,7 @@
 		if (stat("/etc/mtab", &sbuf) != 0)
 		{
 			GAM_DEBUG(DEBUG_INFO, "Could not stat /etc/mtab\n");
+                        return;
 		}
 
 		/* /etc/mtab has changed */
@@ -199,6 +239,17 @@
 
 		mtab_sbuf = sbuf;
 	}
+#elif defined(__FreeBSD__)
+	if (initialized == FALSE)
+	{
+		initialized = TRUE;
+		gam_fs_set ("ufs", GFS_MT_KERNEL, 0);
+		gam_fs_set ("nfs", GFS_MT_POLL, 5);
+		gam_fs_set ("smbfs", GFS_MT_POLL, 5);
+	}
+	gam_fs_getmntinfo ();
+
+#endif
 }
 
 gam_fs_mon_type
@@ -209,10 +260,11 @@
 
 	props = gam_fs_find_fs_props (path);
 
-	if (!props)
-		return GFS_MT_KERNEL;
-
-	return props->mon_type;
+#if defined(ENABLE_INOTIFY) || defined(ENABLE_DNOTIFY) || defined(ENABLE_KQUEUE) || defined(ENABLE_HURD_MACH_NOTIFY)
+	if (props)
+		return props->mon_type;
+#endif
+	return GFS_MT_POLL;
 }
 
 int
