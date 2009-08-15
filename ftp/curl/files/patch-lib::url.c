Different handling of signals and threads.

--- a/lib/url.c
+++ b/lib/url.c
@@ -792,6 +792,10 @@
     data->progress.flags |= PGRS_HIDE;
     data->state.current_speed = -1; /* init to negative == impossible */
 
+#if defined(__FreeBSD_version)
+    data->set.no_signal = TRUE; /* different handling of signals and threads */
+#endif /* __FreeBSD_version */
+
     /* This no longer creates a connection cache here. It is instead made on
        the first call to curl_easy_perform() or when the handle is added to a
        multi stack. */
