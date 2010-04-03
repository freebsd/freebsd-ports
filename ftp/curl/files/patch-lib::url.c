Description: Different handling of signals and threads.
Forwarded: not-needed
Author: Peter Pentchev <roam@FreeBSD.org>
Last-Update: 2010-03-30

--- a/lib/url.c
+++ b/lib/url.c
@@ -831,6 +831,10 @@
     data->progress.flags |= PGRS_HIDE;
     data->state.current_speed = -1; /* init to negative == impossible */
 
+#if defined(__FreeBSD_version)
+    data->set.no_signal = TRUE; /* different handling of signals and threads */
+#endif /* __FreeBSD_version */
+
     /* This no longer creates a connection cache here. It is instead made on
        the first call to curl_easy_perform() or when the handle is added to a
        multi stack. */
