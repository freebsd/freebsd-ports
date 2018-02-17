Description: Different handling of signals and threads.
Forwarded: not-needed
Author: Peter Pentchev <roam@FreeBSD.org>
Last-Update: 2010-12-18

--- lib/url.c.orig	2018-01-23 07:55:37 UTC
+++ lib/url.c
@@ -589,6 +589,10 @@ CURLcode Curl_open(struct Curl_easy **cu
       data->state.current_speed = -1; /* init to negative == impossible */
       data->set.fnmatch = ZERO_NULL;
       data->set.maxconnects = DEFAULT_CONNCACHE_SIZE; /* for easy handles */
+#if defined(__FreeBSD_version)
+      /* different handling of signals and threads */
+      data->set.no_signal = TRUE;
+#endif /* __FreeBSD_version */
 
       Curl_http2_init_state(&data->state);
     }
