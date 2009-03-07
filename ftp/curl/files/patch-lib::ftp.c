Handle CURL_DISABLE_PROXY properly.

--- a/lib/ftp.c
+++ b/lib/ftp.c
@@ -3055,7 +3055,7 @@
                                  bool *done) /* see description above */
 {
   CURLcode result;
-#ifndef CURL_DISABLE_HTTP
+#if !defined(CURL_DISABLE_HTTP) && !defined(CURL_DISABLE_PROXY)
   /* for FTP over HTTP proxy */
   struct HTTP http_proxy;
   struct FTP *ftp_save;
