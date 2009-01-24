--- lib/wwfetch/wwfetch_http.c.old	2009-01-24 15:12:41.000000000 +0200
+++ lib/wwfetch/wwfetch_http.c	2009-01-24 15:15:30.000000000 +0200
@@ -96,7 +96,7 @@
 	if ((handle->lastcurlerror = curl_easy_setopt(handle->curl, CURLOPT_HTTPHEADER, handle->curlheaders)) != CURLE_OK)
 		return WWFETCH_CURL_ERROR;
 
-	if ((handle->lastcurlerror = curl_easy_setopt(handle->curl, CURLOPT_USERAGENT, "gaia/%s", GAIA_VERSION)) != CURLE_OK)
+	if ((handle->lastcurlerror = curl_easy_setopt(handle->curl, CURLOPT_USERAGENT, "gaia/" GAIA_VERSION)) != CURLE_OK)
 		return WWFETCH_CURL_ERROR;
 
 	if ((handle->lastcurlerror = curl_easy_setopt(handle->curl, CURLOPT_URL, url)) != CURLE_OK)
