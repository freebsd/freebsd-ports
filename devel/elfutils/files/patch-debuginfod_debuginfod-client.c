--- debuginfod/debuginfod-client.c.orig	2022-04-26 18:12:52 UTC
+++ debuginfod/debuginfod-client.c
@@ -77,7 +77,7 @@ void debuginfod_end (debuginfod_client *c) { }
 #include <regex.h>
 #include <string.h>
 #include <stdbool.h>
-#include <linux/limits.h>
+//#include <linux/limits.h>
 #include <time.h>
 #include <utime.h>
 #include <sys/syscall.h>
@@ -1070,7 +1070,7 @@ debuginfod_query_server (debuginfod_client *c,
       free (c->winning_headers);
       c->winning_headers = NULL;
     }
-  if ( maxtime > 0 && clock_gettime(CLOCK_MONOTONIC_RAW, &start_time) == -1)
+  if ( maxtime > 0 && clock_gettime(CLOCK_MONOTONIC, &start_time) == -1)
     {
       rc = errno;
       goto out2;
@@ -1081,7 +1081,7 @@ debuginfod_query_server (debuginfod_client *c,
       /* Check to see how long querying is taking. */
       if (maxtime > 0)
         {
-          if (clock_gettime(CLOCK_MONOTONIC_RAW, &cur_time) == -1)
+          if (clock_gettime(CLOCK_MONOTONIC, &cur_time) == -1)
             {
               rc = errno;
               goto out2;
@@ -1090,7 +1090,7 @@ debuginfod_query_server (debuginfod_client *c,
           if ( delta >  maxtime)
             {
               dprintf(vfd, "Timeout with max time=%lds and transfer time=%lds\n", maxtime, delta );
-              rc = -ETIME;
+              rc = -EINVAL;
               goto out2;
             }
         }
@@ -1260,7 +1260,7 @@ debuginfod_query_server (debuginfod_client *c,
                 case CURLE_TOO_MANY_REDIRECTS: rc = -EMLINK; break;
                 case CURLE_SEND_ERROR: rc = -ECONNRESET; break;
                 case CURLE_RECV_ERROR: rc = -ECONNRESET; break;
-                case CURLE_OPERATION_TIMEDOUT: rc = -ETIME; break;
+                case CURLE_OPERATION_TIMEDOUT: rc = -EINVAL; break;
                 case CURLE_HTTP_RETURNED_ERROR:
                   ok0 = curl_easy_getinfo (msg->easy_handle,
                                           CURLINFO_RESPONSE_CODE,
