--- docs/examples/getredirect.c.orig	2016-01-30 11:01:12 UTC
+++ docs/examples/getredirect.c
@@ -48,7 +48,7 @@ int main(void)
     else {
       res = curl_easy_getinfo(curl, CURLINFO_RESPONSE_CODE, &response_code);
       if((res == CURLE_OK) &&
-         ((code / 100) != 3)) {
+         ((response_code / 100) != 3)) {
         /* a redirect implies a 3xx response code */
         fprintf(stderr, "Not a redirect.\n");
       }
