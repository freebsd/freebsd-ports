--- src/auth_url.c.orig	Thu Dec  7 17:26:49 2006
+++ src/auth_url.c	Thu Dec  7 17:27:05 2006
@@ -518,7 +518,9 @@
     curl_easy_setopt (url_info->handle, CURLOPT_WRITEDATA, url_info->handle);
     curl_easy_setopt (url_info->handle, CURLOPT_NOSIGNAL, 1L);
     curl_easy_setopt (url_info->handle, CURLOPT_TIMEOUT, 15L);
+#if LIBCURL_VERSION_NUM < 0x071000
     curl_easy_setopt (url_info->handle, CURLOPT_PASSWDFUNCTION, my_getpass);
+#endif
     curl_easy_setopt (url_info->handle, CURLOPT_ERRORBUFFER, &url_info->errormsg[0]);
 
     if (url_info->username && url_info->password)
