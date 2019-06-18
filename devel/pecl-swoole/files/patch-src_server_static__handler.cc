--- src/server/static_handler.cc.orig	2019-06-18 03:17:11 UTC
+++ src/server/static_handler.cc
@@ -168,7 +168,7 @@ int static_handler::send_response()
         {
             date_format = SW_HTTP_ASCTIME_DATE;
         }
-        if (date_format && mktime(&tm3) - (int) timezone >= file_mtime)
+        if (date_format && mktime(&tm3) - (long)timezone >= file_mtime)
         {
             response.info.len = sw_snprintf(header_buffer, sizeof(header_buffer), "HTTP/1.1 304 Not Modified\r\n"
                     "%s"
