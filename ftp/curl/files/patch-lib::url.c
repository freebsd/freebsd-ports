Description: Different handling of signals and threads.
Forwarded: not-needed
Author: Peter Pentchev <roam@FreeBSD.org>
Last-Update: 2010-12-18

--- a/lib/url.c
+++ b/lib/url.c
@@ -857,6 +857,10 @@
     data->progress.flags |= PGRS_HIDE;
     data->state.current_speed = -1; /* init to negative == impossible */
 
+#if defined(__FreeBSD_version)
+    data->set.no_signal = TRUE; /* different handling of signals and threads */
+#endif /* __FreeBSD_version */
+
     data->wildcard.state = CURLWC_INIT;
     data->wildcard.filelist = NULL;
     data->set.fnmatch = ZERO_NULL;
