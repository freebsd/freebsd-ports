Obtained from:	https://github.com/curl/curl/commit/f4f485c17b9a8b41c23ad1fa9fbcfc1973172ead

--- src/tool_setopt.c.orig	2019-05-16 20:54:53 UTC
+++ src/tool_setopt.c
@@ -713,4 +713,56 @@ CURLcode tool_setopt(CURL *curl, bool st
   return ret;
 }
 
+#else /* CURL_DISABLE_LIBCURL_OPTION */
+
+#include "tool_cfgable.h"
+#include "tool_setopt.h"
+
 #endif /* CURL_DISABLE_LIBCURL_OPTION */
+
+CURLcode tool_real_error(CURLcode result, CURLoption tag)
+{
+#ifdef CURL_DISABLE_PROXY
+  switch(tag) {
+  case CURLOPT_HAPROXYPROTOCOL:
+  case CURLOPT_HTTPPROXYTUNNEL:
+  case CURLOPT_NOPROXY:
+  case CURLOPT_PRE_PROXY:
+  case CURLOPT_PROXY:
+  case CURLOPT_PROXYAUTH:
+  case CURLOPT_PROXY_CAINFO:
+  case CURLOPT_PROXY_CAPATH:
+  case CURLOPT_PROXY_CRLFILE:
+  case CURLOPT_PROXYHEADER:
+  case CURLOPT_PROXY_KEYPASSWD:
+  case CURLOPT_PROXYPASSWORD:
+  case CURLOPT_PROXY_PINNEDPUBLICKEY:
+  case CURLOPT_PROXYPORT:
+  case CURLOPT_PROXY_SERVICE_NAME:
+  case CURLOPT_PROXY_SSLCERT:
+  case CURLOPT_PROXY_SSLCERTTYPE:
+  case CURLOPT_PROXY_SSL_CIPHER_LIST:
+  case CURLOPT_PROXY_SSLKEY:
+  case CURLOPT_PROXY_SSLKEYTYPE:
+  case CURLOPT_PROXY_SSL_OPTIONS:
+  case CURLOPT_PROXY_SSL_VERIFYHOST:
+  case CURLOPT_PROXY_SSL_VERIFYPEER:
+  case CURLOPT_PROXY_SSLVERSION:
+  case CURLOPT_PROXY_TLS13_CIPHERS:
+  case CURLOPT_PROXY_TLSAUTH_PASSWORD:
+  case CURLOPT_PROXY_TLSAUTH_TYPE:
+  case CURLOPT_PROXY_TLSAUTH_USERNAME:
+  case CURLOPT_PROXY_TRANSFER_MODE:
+  case CURLOPT_PROXYTYPE:
+  case CURLOPT_PROXYUSERNAME:
+  case CURLOPT_PROXYUSERPWD:
+    return CURLE_OK; /* pretend it worked */
+  default:
+    break;
+  }
+#else
+  (void)tag;
+#endif
+  return result;
+}
+
