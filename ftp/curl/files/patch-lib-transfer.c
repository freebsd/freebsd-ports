Obtained from:	https://github.com/bagder/curl/commit/903b6e05565bf826b4194447864288642214b094

--- lib/transfer.c.orig	2015-06-14 21:31:01 UTC
+++ lib/transfer.c
@@ -1315,6 +1315,11 @@ CURLcode Curl_pretransfer(struct Session
   Curl_safefree(data->info.wouldredirect);
   data->info.wouldredirect = NULL;
 
+  if(data->set.httpreq == HTTPREQ_PUT)
+    data->state.infilesize = data->set.filesize;
+  else
+    data->state.infilesize = data->set.postfieldsize;
+
   /* If there is a list of cookie files to read, do it now! */
   if(data->change.cookielist)
     Curl_cookie_loadfiles(data);
