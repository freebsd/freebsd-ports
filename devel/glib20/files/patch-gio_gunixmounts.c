--- gio/gunixmounts.c.orig	2014-09-22 15:42:12.000000000 +0200
+++ gio/gunixmounts.c	2014-09-28 10:03:52.141514611 +0200
@@ -150,6 +150,7 @@
   GFileMonitor *fstab_monitor;
   GFileMonitor *mtab_monitor;
 
+  guint mount_poller_source;
   GList *mount_poller_mounts;
 
   GSource *proc_mounts_watch_source;
@@ -1293,6 +1294,13 @@
 
   g_list_free_full (monitor->mount_poller_mounts, (GDestroyNotify)g_unix_mount_free);
 
+  if (monitor->mount_poller_source > 0)
+    {
+      g_source_remove (monitor->mount_poller_source);
+      g_list_foreach (monitor->mount_poller_mounts, (GFunc)g_unix_mount_free, NULL);
+      g_list_free (monitor->mount_poller_mounts);
+    }
+
   the_mount_monitor = NULL;
 
   G_OBJECT_CLASS (g_unix_mount_monitor_parent_class)->finalize (object);
