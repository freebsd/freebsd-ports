--- src/main.c.orig	Wed Dec 10 15:14:31 2003
+++ src/main.c	Wed Dec 10 15:14:48 2003
@@ -3350,7 +3350,7 @@
            closed, as is done above here */
         if(config->remote_time && outs.filename) {
           /* as libcurl if we got a time. Pretty please */
-          long filetime;
+          time_t filetime;
           curl_easy_getinfo(curl, CURLINFO_FILETIME, &filetime);
           if(filetime >= 0) {
             struct utimbuf times;
