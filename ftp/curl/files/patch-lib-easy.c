Obtained from:	https://github.com/curl/curl/commit/3bfda07004a5739fb306e55cb9529ba3de35fbdb

--- lib/easy.c.orig	2020-03-09 15:31:01 UTC
+++ lib/easy.c
@@ -884,14 +884,25 @@ struct Curl_easy *curl_easy_duphandle(struct Curl_easy
     goto fail;
 
 #ifdef USE_ARES
-  if(Curl_set_dns_servers(outcurl, data->set.str[STRING_DNS_SERVERS]))
-    goto fail;
-  if(Curl_set_dns_interface(outcurl, data->set.str[STRING_DNS_INTERFACE]))
-    goto fail;
-  if(Curl_set_dns_local_ip4(outcurl, data->set.str[STRING_DNS_LOCAL_IP4]))
-    goto fail;
-  if(Curl_set_dns_local_ip6(outcurl, data->set.str[STRING_DNS_LOCAL_IP6]))
-    goto fail;
+  {
+    CURLcode rc;
+
+    rc = Curl_set_dns_servers(outcurl, data->set.str[STRING_DNS_SERVERS]);
+    if(rc && rc != CURLE_NOT_BUILT_IN)
+      goto fail;
+
+    rc = Curl_set_dns_interface(outcurl, data->set.str[STRING_DNS_INTERFACE]);
+    if(rc && rc != CURLE_NOT_BUILT_IN)
+      goto fail;
+
+    rc = Curl_set_dns_local_ip4(outcurl, data->set.str[STRING_DNS_LOCAL_IP4]);
+    if(rc && rc != CURLE_NOT_BUILT_IN)
+      goto fail;
+
+    rc = Curl_set_dns_local_ip6(outcurl, data->set.str[STRING_DNS_LOCAL_IP6]);
+    if(rc && rc != CURLE_NOT_BUILT_IN)
+      goto fail;
+  }
 #endif /* USE_ARES */
 
   Curl_convert_setup(outcurl);
