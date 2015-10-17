https://bugzilla.gnome.org/show_bug.cgi?id=753378

--- gio/gunionvolumemonitor.c.orig	2015-09-25 11:23:00.429587000 +0200
+++ gio/gunionvolumemonitor.c	2015-09-25 11:23:12.787618000 +0200
@@ -592,9 +592,9 @@ _g_mount_get_for_mount_path (const gchar
 
   if (klass->get_mount_for_mount_path)
     {
-      g_rec_mutex_lock (&the_volume_monitor_mutex);
+//      g_rec_mutex_lock (&the_volume_monitor_mutex);
       mount = klass->get_mount_for_mount_path (mount_path, cancellable);
-      g_rec_mutex_unlock (&the_volume_monitor_mutex);
+//      g_rec_mutex_unlock (&the_volume_monitor_mutex);
     }
 
   /* TODO: How do we know this succeeded? Keep in mind that the native
