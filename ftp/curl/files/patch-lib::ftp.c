--- ../../../tags/curl-7.19.2-stock/lib/ftp.c	2009-01-23 18:11:47.000000000 +0200
+++ lib/ftp.c	2009-01-26 03:31:07.000000000 +0200
@@ -1901,7 +1901,7 @@
     result = CURLE_COULDNT_CONNECT;
     break;
   }
-#ifndef CURL_DISABLE_HTTP
+#if !defined(CURL_DISABLE_HTTP) && !defined(CURL_DISABLE_PROXY)
   if(conn->bits.tunnel_proxy && conn->bits.httpproxy) {
     /* FIX: this MUST wait for a proper connect first if 'connected' is
      * FALSE */
@@ -1927,7 +1927,7 @@
     if(CURLE_OK != result)
       return result;
   }
-#endif   /* CURL_DISABLE_HTTP */
+#endif   /* CURL_DISABLE_HTTP || CURL_DISABLE_PROXY */
 
   state(conn, FTP_STOP); /* this phase is completed */
 
@@ -3056,7 +3056,7 @@
                                  bool *done) /* see description above */
 {
   CURLcode result;
-#ifndef CURL_DISABLE_HTTP
+#if !defined(CURL_DISABLE_HTTP) && !defined(CURL_DISABLE_PROXY)
   /* for FTP over HTTP proxy */
   struct HTTP http_proxy;
   struct FTP *ftp_save;
@@ -3079,7 +3079,7 @@
 
   ftpc->response_time = RESP_TIMEOUT; /* set default response time-out */
 
-#ifndef CURL_DISABLE_HTTP
+#if !defined(CURL_DISABLE_HTTP) && !defined(CURL_DISABLE_PROXY)
   if(conn->bits.tunnel_proxy && conn->bits.httpproxy) {
     /* BLOCKING */
     /* We want "seamless" FTP operations through HTTP proxy tunnel */
@@ -3102,7 +3102,7 @@
     if(CURLE_OK != result)
       return result;
   }
-#endif   /* CURL_DISABLE_HTTP */
+#endif   /* CURL_DISABLE_HTTP || CURL_DISABLE_PROXY */
 
   if(conn->protocol & PROT_FTPS) {
     /* BLOCKING */
