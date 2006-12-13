--- ogg123/http_transport.c.orig	Fri Dec  1 16:25:40 2006
+++ ogg123/http_transport.c	Fri Dec  1 16:29:16 2006
@@ -116,7 +116,9 @@
   if (inputOpts.ProxyTunnel)
     curl_easy_setopt (handle, CURLOPT_HTTPPROXYTUNNEL, inputOpts.ProxyTunnel);
   */
+#if LIBCURL_VERSION_NUM < 0x071000
   curl_easy_setopt(handle, CURLOPT_MUTE, 1);
+#endif
   curl_easy_setopt(handle, CURLOPT_ERRORBUFFER, private->error);
   curl_easy_setopt(handle, CURLOPT_PROGRESSFUNCTION, progress_callback);
   curl_easy_setopt(handle, CURLOPT_PROGRESSDATA, private);
