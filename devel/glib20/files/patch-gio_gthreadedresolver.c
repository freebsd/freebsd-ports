Upstream bug: https://gitlab.gnome.org/GNOME/glib/issues/1697

--- gio/gthreadedresolver.c.orig
+++ gio/gthreadedresolver.c
@@ -836,6 +836,7 @@
    * worker thread. (Although the workers would get reused by the
    * #GThreadPool.) */
   struct __res_state res;
+  memset( &res, 0, sizeof( res ));
   if (res_ninit (&res) != 0)
     {
       g_task_return_new_error (task, G_RESOLVER_ERROR, G_RESOLVER_ERROR_INTERNAL,
