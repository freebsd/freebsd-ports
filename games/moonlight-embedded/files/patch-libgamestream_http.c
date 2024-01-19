--- libgamestream/http.c.orig	2023-11-03 06:08:34 UTC
+++ libgamestream/http.c
@@ -73,6 +73,9 @@ int http_init(const char* keyDirectory, int logLevel) 
 int http_request(char* url, PHTTP_DATA data) {
   curl_easy_setopt(curl, CURLOPT_WRITEDATA, data);
   curl_easy_setopt(curl, CURLOPT_URL, url);
+#ifdef __FreeBSD__
+  curl_easy_setopt(curl, CURLOPT_FORBID_REUSE, 1);
+#endif
 
   if (debug)
     printf("Request %s\n", url);
