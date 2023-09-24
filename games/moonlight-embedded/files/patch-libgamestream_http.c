--- libgamestream/http.c.orig	2023-09-01 23:40:56 UTC
+++ libgamestream/http.c
@@ -73,6 +73,9 @@ int http_init(const char* keyDirectory, int logLevel) 
 int http_request(char* url, PHTTP_DATA data) {
   curl_easy_setopt(curl, CURLOPT_WRITEDATA, data);
   curl_easy_setopt(curl, CURLOPT_URL, url);
+  curl_easy_setopt(curl, CURLOPT_TCP_FASTOPEN, 1L);
+  curl_easy_setopt(curl, CURLOPT_FRESH_CONNECT, 1);
+  curl_easy_setopt(curl, CURLOPT_FORBID_REUSE, 1);
 
   if (debug)
     printf("Request %s\n", url);
