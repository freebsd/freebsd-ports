Description: Different handling of signals and threads.
Forwarded: not-needed
Author: Peter Pentchev <roam@FreeBSD.org>
Last-Update: 2010-12-18

--- lib/url.c.orig	2015-04-22 05:55:54 UTC
+++ lib/url.c
@@ -659,6 +659,10 @@ CURLcode Curl_open(struct SessionHandle 
     data->progress.flags |= PGRS_HIDE;
     data->state.current_speed = -1; /* init to negative == impossible */
 
+#if defined(__FreeBSD_version)
+    data->set.no_signal = TRUE; /* different handling of signals and threads */
+#endif /* __FreeBSD_version */
+
     data->wildcard.state = CURLWC_INIT;
     data->wildcard.filelist = NULL;
     data->set.fnmatch = ZERO_NULL;
