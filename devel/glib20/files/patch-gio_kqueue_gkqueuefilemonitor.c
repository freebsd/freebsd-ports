https://bugzilla.gnome.org/show_bug.cgi?id=739424
https://bug739424.bugzilla-attachments.gnome.org/attachment.cgi?id=351191

--- gio/kqueue/gkqueuefilemonitor.c.orig	2018-01-15 21:00:32.535064000 +0100
+++ gio/kqueue/gkqueuefilemonitor.c	2018-01-15 21:07:20.920334000 +0100
@@ -29,6 +29,15 @@
 #include <gio/gfile.h>
 #include <gio/giomodule.h>
 
+/*
+ * Because ``kqueue_sub'' are not refcounted, we need
+ * ensure no other thread is getting a reference to
+ * the element we want to free.
+ *
+ * That's why _kh_cancel_sub() must be called with
+ * this lock held to prevent a race.
+ */
+G_LOCK_EXTERN (hash_lock);
 
 struct _GKqueueFileMonitor
 {
@@ -80,9 +89,11 @@ g_kqueue_file_monitor_finalize (GObject *object)
 
   if (kqueue_monitor->sub)
     {
+      G_LOCK (hash_lock);
       _kh_cancel_sub (kqueue_monitor->sub);
       _kh_sub_free (kqueue_monitor->sub);
       kqueue_monitor->sub = NULL;
+      G_UNLOCK (hash_lock);
     }
 
   if (kqueue_monitor->fallback)
@@ -181,9 +192,11 @@ g_kqueue_file_monitor_cancel (GFileMonitor *monitor)
 
   if (kqueue_monitor->sub)
     {
+      G_LOCK (hash_lock);
       _kh_cancel_sub (kqueue_monitor->sub);
       _kh_sub_free (kqueue_monitor->sub);
       kqueue_monitor->sub = NULL;
+      G_UNLOCK (hash_lock);
     }
   else if (kqueue_monitor->fallback)
     {
