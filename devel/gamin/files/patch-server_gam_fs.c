--- server/gam_fs.c.orig	Fri Aug  5 18:31:46 2005
+++ server/gam_fs.c	Sat Feb 11 01:44:04 2006
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
 
@@ -21,9 +26,13 @@ typedef struct _gam_fs_properties {
 typedef struct _gam_fs {
 	char *path;
 	char *fsname;
+	guint64 flags;
 } gam_fs;
 
 static gboolean initialized = FALSE;
+#ifdef __FreeBSD__
+static gboolean initializing = FALSE;
+#endif
 static GList *filesystems = NULL;
 static GList *fs_props = NULL;
 static struct stat mtab_sbuf;
@@ -110,6 +119,7 @@ gam_fs_filesystem_sort_cb (gconstpointer
 	return strlen(fsb->path) - strlen (fsa->path);
 }
 
+#ifdef __linux__
 static void
 gam_fs_scan_mtab (void)
 {
@@ -165,10 +175,41 @@ gam_fs_scan_mtab (void)
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
+		fs->flags = stat[i].f_flags;
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
@@ -181,6 +222,7 @@ gam_fs_init (void)
 		if (stat("/etc/mtab", &mtab_sbuf) != 0)
 		{
 			GAM_DEBUG(DEBUG_INFO, "Could not stat /etc/mtab\n");
+                        return;
 		}
 		gam_fs_scan_mtab ();
 	} else {
@@ -189,6 +231,7 @@ gam_fs_init (void)
 		if (stat("/etc/mtab", &sbuf) != 0)
 		{
 			GAM_DEBUG(DEBUG_INFO, "Could not stat /etc/mtab\n");
+                        return;
 		}
 
 		/* /etc/mtab has changed */
@@ -199,6 +242,54 @@ gam_fs_init (void)
 
 		mtab_sbuf = sbuf;
 	}
+#elif defined(__FreeBSD__)
+	if (initialized == FALSE && initializing == FALSE)
+	{
+		GList *iterator = NULL;
+		GHashTable *fs_hash = NULL;
+		gam_fs *fs = NULL;
+
+		initialized = TRUE;
+		initializing = TRUE;
+
+		gam_fs_getmntinfo ();
+
+		iterator = filesystems;
+		fs_hash = g_hash_table_new_full (g_str_hash, g_str_equal, g_free, NULL);
+
+		while (iterator) {
+			fs = iterator->data;
+
+			if (!g_hash_table_lookup (fs_hash, fs->fsname)) {
+				if (fs->flags & MNT_LOCAL)
+					gam_fs_set (fs->fsname, GFS_MT_KERNEL, 0);
+				else
+					gam_fs_set (fs->fsname, GFS_MT_POLL, 5);
+
+				g_hash_table_insert (fs_hash, g_strdup (fs->fsname), GINT_TO_POINTER (1));
+			}
+
+			iterator = g_list_next (iterator);
+		}
+
+		g_hash_table_destroy (fs_hash);
+		initializing = FALSE;
+	} else if (initializing == FALSE) {
+		struct stat sbuf;
+
+		if (stat ("/etc/fstab", &sbuf) != 0) {
+			GAM_DEBUG(DEBUG_INFO, "Could not stat /etc/fstab\n");
+			return;
+		}
+
+		if (sbuf.st_mtime != mtab_sbuf.st_mtime) {
+			GAM_DEBUG(DEBUG_INFO, "Updating list of mounted filesystems\n");
+			gam_fs_getmntinfo ();
+		}
+
+		mtab_sbuf = sbuf;
+	}
+#endif
 }
 
 gam_fs_mon_type
@@ -209,10 +300,13 @@ gam_fs_get_mon_type (const char *path)
 
 	props = gam_fs_find_fs_props (path);
 
-	if (!props)
-		return GFS_MT_KERNEL;
-
-	return props->mon_type;
+#if (defined(ENABLE_INOTIFY) || defined(ENABLE_DNOTIFY) || defined(ENABLE_KQUEUE) || defined(ENABLE_HURD_MACH_NOTIFY)) && defined(USE_GAMIN_POLLER)
+	if (props)
+		return props->mon_type;
+#elif !defined(USE_GAMIN_POLLER)
+	return GFS_MT_KERNEL;
+#endif
+	return GFS_MT_POLL;
 }
 
 int
