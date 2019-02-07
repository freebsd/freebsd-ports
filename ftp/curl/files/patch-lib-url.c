Description: Different handling of signals and threads.
Forwarded: not-needed
Author: Peter Pentchev <roam@FreeBSD.org>
Last-Update: 2010-12-18

--- lib/url.c.orig	2019-02-05 14:00:12 UTC
+++ lib/url.c
@@ -536,6 +536,10 @@ CURLcode Curl_init_userdefined(struct Cu
   set->fnmatch = ZERO_NULL;
   set->upkeep_interval_ms = CURL_UPKEEP_INTERVAL_DEFAULT;
   set->maxconnects = DEFAULT_CONNCACHE_SIZE; /* for easy handles */
+#if defined(__FreeBSD_version)
+  /* different handling of signals and threads */
+  set->no_signal = TRUE;
+#endif
   set->http09_allowed = TRUE;
   set->httpversion =
 #ifdef USE_NGHTTP2
