--- ./plugins/cover-thumbnailer/cover-thumbnailer.c.orig	2013-01-12 11:14:28.000000000 +0000
+++ ./plugins/cover-thumbnailer/cover-thumbnailer.c	2013-01-12 22:37:33.000000000 +0000
@@ -274,7 +274,12 @@
   curl_handle = curl_easy_init ();
   curl_multi_add_handle (cover->curl_multi, curl_handle);
   /* curl_easy_setopt (curl_handle, CURLOPT_VERBOSE, TRUE); */
+
+  /* CURLOPT_TCP_KEEPALIVE appears from 7.25.0 */
+#if LIBCURL_VERSION_MINOR >= 25 
   curl_easy_setopt (curl_handle, CURLOPT_TCP_KEEPALIVE, TRUE);
+#endif
+
   curl_easy_setopt (curl_handle, CURLOPT_URL, url);
   curl_easy_setopt (curl_handle, CURLOPT_USERAGENT, PACKAGE_NAME "/" PACKAGE_VERSION);
 
