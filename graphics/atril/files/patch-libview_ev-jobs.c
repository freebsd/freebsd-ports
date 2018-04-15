--- libview/ev-jobs.c.orig	2018-03-22 15:13:28 UTC
+++ libview/ev-jobs.c
@@ -876,8 +876,6 @@ snapshot_callback(WebKitWebView *webview,
 	gtk_widget_destroy (gtk_widget_get_toplevel (GTK_WIDGET (webview)));
 }
 
-#endif  /* ENABLE_EPUB */
-
 static void
 web_thumbnail_get_screenshot_cb (WebKitWebView  *webview,
                                  WebKitLoadEvent event,
@@ -909,6 +907,8 @@ webview_load_failed_cb (WebKitWebView  *webview,
 	gtk_widget_destroy (gtk_widget_get_toplevel (GTK_WIDGET (webview)));
 	return TRUE;
 }
+
+#endif  /* ENABLE_EPUB */
 
 static gboolean
 ev_job_thumbnail_run (EvJob *job)
