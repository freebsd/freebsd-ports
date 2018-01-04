Description: Different handling of signals and threads.
Forwarded: not-needed
Author: Peter Pentchev <roam@FreeBSD.org>
Last-Update: 2010-12-18

--- lib/url.c.orig	2017-11-27 12:50:52 UTC
+++ lib/url.c
@@ -591,6 +591,9 @@ CURLcode Curl_open(struct Curl_easy **cu
       data->state.current_speed = -1; /* init to negative == impossible */
       data->set.fnmatch = ZERO_NULL;
       data->set.maxconnects = DEFAULT_CONNCACHE_SIZE; /* for easy handles */
+#if defined(__FreeBSD_version)
+      data->set.no_signal = TRUE; /* different handling of signals and threads */
+#endif /* __FreeBSD_version */
 
       Curl_http2_init_state(&data->state);
     }
