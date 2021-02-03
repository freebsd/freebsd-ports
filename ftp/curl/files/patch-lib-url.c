Obtained from:	https://github.com/curl/curl/commit/0936ecd0ee5e3e28c098fefc9e2c0e6847cb7a82

Description: Different handling of signals and threads.
Forwarded: not-needed
Author: Peter Pentchev <roam@FreeBSD.org>
Last-Update: 2010-12-18

--- lib/url.c.orig	2020-12-08 07:39:35 UTC
+++ lib/url.c
@@ -607,6 +607,10 @@ CURLcode Curl_init_userdefined(struct Curl_easy *data)
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
@@ -3940,20 +3944,6 @@ CURLcode Curl_setup_conn(struct connectdata *conn,
      lingering set from a previous invoke */
   conn->bits.proxy_connect_closed = FALSE;
 #endif
-  /*
-   * Set user-agent. Used for HTTP, but since we can attempt to tunnel
-   * basically anything through a http proxy we can't limit this based on
-   * protocol.
-   */
-  if(data->set.str[STRING_USERAGENT]) {
-    Curl_safefree(data->state.aptr.uagent);
-    data->state.aptr.uagent =
-      aprintf("User-Agent: %s\r\n", data->set.str[STRING_USERAGENT]);
-    if(!data->state.aptr.uagent)
-      return CURLE_OUT_OF_MEMORY;
-  }
-
-  data->req.headerbytecount = 0;
 
 #ifdef CURL_DO_LINEEND_CONV
   data->state.crlf_conversions = 0; /* reset CRLF conversion counter */
