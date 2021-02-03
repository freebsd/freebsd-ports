Obtained from:	https://github.com/curl/curl/commit/0936ecd0ee5e3e28c098fefc9e2c0e6847cb7a82

--- lib/transfer.c.orig	2020-12-08 08:14:13 UTC
+++ lib/transfer.c
@@ -1532,6 +1532,20 @@ CURLcode Curl_pretransfer(struct Curl_easy *data)
     Curl_hsts_loadcb(data, data->hsts);
   }
 
+  /*
+   * Set user-agent. Used for HTTP, but since we can attempt to tunnel
+   * basically anything through a http proxy we can't limit this based on
+   * protocol.
+   */
+  if(data->set.str[STRING_USERAGENT]) {
+    Curl_safefree(data->state.aptr.uagent);
+    data->state.aptr.uagent =
+      aprintf("User-Agent: %s\r\n", data->set.str[STRING_USERAGENT]);
+    if(!data->state.aptr.uagent)
+      return CURLE_OUT_OF_MEMORY;
+  }
+
+  data->req.headerbytecount = 0;
   return result;
 }
 
