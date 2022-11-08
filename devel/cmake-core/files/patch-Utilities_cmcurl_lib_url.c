--- Utilities/cmcurl/lib/url.c.orig	2022-08-04 13:53:57 UTC
+++ Utilities/cmcurl/lib/url.c
@@ -626,6 +626,10 @@ CURLcode Curl_init_userdefined(struct Curl_easy *data)
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
