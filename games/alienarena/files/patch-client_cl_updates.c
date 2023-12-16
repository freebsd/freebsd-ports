--- client/cl_updates.c	2023-11-12 22:09:46.989672000 -0500
+++ client/cl_updates.c	2023-11-12 22:10:10.652785000 -0500
@@ -250,14 +250,14 @@
 	easyhandle = curl_easy_init();
 
 	// Set Http version to 1.1, somehow this seems to be needed for the multi-download
-	if (curl_easy_setopt(easyhandle, CURLOPT_HTTP_VERSION, (long) CURL_HTTP_VERSION_1_1) != CURLE_OK) return false;
+	if (curl_easy_setopt(easyhandle, CURLOPT_HTTP_VERSION, (long) CURL_HTTP_VERSION_1_1) != CURLE_OK) return;
 
 	// Follow redirects to https - but this doesn't seem to be working
-	if (curl_easy_setopt(easyhandle, CURLOPT_FOLLOWLOCATION, 1L) != CURLE_OK) return false;
-	if (curl_easy_setopt(easyhandle, CURLOPT_MAXREDIRS, 3L) != CURLE_OK) return false;
+	if (curl_easy_setopt(easyhandle, CURLOPT_FOLLOWLOCATION, 1L) != CURLE_OK) return;
+	if (curl_easy_setopt(easyhandle, CURLOPT_MAXREDIRS, 3L) != CURLE_OK) return;
 	
 	// Don't verify that the host matches the certificate
-	if (curl_easy_setopt(easyhandle, CURLOPT_SSL_VERIFYHOST, 0L) != CURLE_OK) return false;
+	if (curl_easy_setopt(easyhandle, CURLOPT_SSL_VERIFYHOST, 0L) != CURLE_OK) return;
 
 	Com_sprintf(url, sizeof(url), "%s", cl_latest_game_version_url->string);
 
