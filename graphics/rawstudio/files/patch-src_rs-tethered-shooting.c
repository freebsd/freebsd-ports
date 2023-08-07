--- src/rs-tethered-shooting.c.orig	2011-03-26 02:07:57 UTC
+++ src/rs-tethered-shooting.c
@@ -115,13 +115,12 @@ append_status(TetherInfo *t, const gchar *format, ...)
 }
 
 static void
-ctx_error_func (GPContext *context, const char *format, va_list args, void *data)
+ctx_error_func (GPContext *context, const char *str, void *data)
 {
 	gdk_threads_lock();
 	TetherInfo *t = (TetherInfo*)data;
 	append_status (t, _("Gphoto2 reported Context Error:\n"));
-	append_status_va_list(t, format, args);
-	append_status  (t, "\n");
+	append_status(t, "%s\n", str);
 	if (t->async_thread_id && t->async_thread_id != g_thread_self())
 		shutdown_async_thread(t);
 	t->keep_thread_running = FALSE;
@@ -129,12 +128,11 @@ ctx_error_func (GPContext *context, const char *format
 }
 
 static void
-ctx_status_func (GPContext *context, const char *format, va_list args, void *data)
+ctx_status_func (GPContext *context, const char *str, void *data)
 {
 	TetherInfo *t = (TetherInfo*)data;
 	gdk_threads_lock();
-	append_status_va_list(t, format, args);
-	append_status  (t, "\n");
+	append_status(t, "%s\n", str);
 	gdk_threads_unlock();
 }
 
