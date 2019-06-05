Description: Different handling of signals and threads.
Forwarded: not-needed
Author: Peter Pentchev <roam@FreeBSD.org>
Last-Update: 2010-12-18

--- lib/url.c.orig	2019-05-21 17:57:39 UTC
+++ lib/url.c
@@ -552,6 +552,10 @@ CURLcode Curl_init_userdefined(struct Cu
     CURL_HTTP_VERSION_1_1
 #endif
     ;
+#if defined(__FreeBSD_version)
+  /* different handling of signals and threads */
+  set->no_signal = TRUE;
+#endif
   Curl_http2_init_userset(set);
   return result;
 }
