--- lib/asyn-thread.c.orig	2014-09-08 05:15:44.000000000 +0800
+++ lib/asyn-thread.c	2014-10-09 08:28:38.036235206 +0800
@@ -541,7 +541,7 @@
       td->poll_interval = 250;
 
     td->interval_end = elapsed + td->poll_interval;
-    Curl_expire_latest(conn->data, td->poll_interval);
+    Curl_expire(conn->data, td->poll_interval);
   }
 
   return CURLE_OK;
