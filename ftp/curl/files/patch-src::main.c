--- src/main.c.orig	Mon May 12 05:45:57 2003
+++ src/main.c	Sun Jun 15 18:58:50 2003
@@ -3011,7 +3011,7 @@
          closed, as is done above here */
       if(config->remote_time && outs.filename) {
         /* as libcurl if we got a time. Pretty please */
-        long filetime;
+        time_t filetime;
         curl_easy_getinfo(curl, CURLINFO_FILETIME, &filetime);
         if(filetime >= 0) {
           struct utimbuf times;
