
$FreeBSD$

--- network.c.orig
+++ network.c
@@ -225,7 +225,8 @@
      * a html page and not the stream */
     snprintf(http_request, sizeof(http_request), "GET /%s HTTP/1.0\r\n"
 /*  "User-Agent: Mozilla/2.0 (Win95; I)\r\n" */
-             "Pragma: no-cache\r\n" "Host: %s\r\n" "Accept: */*\r\n" "\r\n", filename, host);
+             "User-Agent: mpg321/%s\r\n"
+             "Pragma: no-cache\r\n" "Host: %s\r\n" "Accept: */*\r\n" "\r\n", filename, VERSION, host);
 
     send(tcp_sock, http_request, strlen(http_request), 0);
 
