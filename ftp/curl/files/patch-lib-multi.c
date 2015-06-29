Obtained from:	https://github.com/bagder/curl/commit/903b6e05565bf826b4194447864288642214b094

--- lib/multi.c.orig	2015-06-15 21:14:25 UTC
+++ lib/multi.c
@@ -402,11 +402,6 @@ CURLMcode curl_multi_add_handle(CURLM *m
   /* Point to the multi's connection cache */
   data->state.conn_cache = &multi->conn_cache;
 
-  if(data->set.httpreq == HTTPREQ_PUT)
-    data->state.infilesize = data->set.filesize;
-  else
-    data->state.infilesize = data->set.postfieldsize;
-
   /* This adds the new entry at the 'end' of the doubly-linked circular
      list of SessionHandle structs to try and maintain a FIFO queue so
      the pipelined requests are in order. */
