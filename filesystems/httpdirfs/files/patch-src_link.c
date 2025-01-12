--- src/link.c.orig	2025-01-12 11:28:19 UTC
+++ src/link.c
@@ -995,7 +995,7 @@ static CURL *Link_download_curl_setup(Link *link, size
     size_t end = start + req_size - 1;
 
     char range_str[64];
-    snprintf(range_str, sizeof(range_str), "%lu-%lu", start, end);
+    snprintf(range_str, sizeof(range_str), "%zu-%zu", start, end);
     lprintf(debug, "%s: %s\n", link->linkname, range_str);
 
     CURL *curl = Link_to_curl(link);
