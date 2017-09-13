--- src/TaskStore.vala.orig	2016-12-18 13:54:36 UTC
+++ src/TaskStore.vala
@@ -86,7 +86,11 @@ class TaskStore : Gtk.ListStore {
     public void remove_task (Gtk.TreeIter iter) {
         bool is_active_task = compare_tasks (iter);
         var _active_task = active_task;
+#if VALA_0_36
+        this.remove (ref iter);
+#else
         this.remove (iter);
+#endif
         if (is_active_task && _active_task == active_task) {
             active_task = null;
             refresh_active_task ();
