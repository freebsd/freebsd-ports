
$FreeBSD$

--- lib/inets/src/http_client/httpc_request.erl.orig
+++ lib/inets/src/http_client/httpc_request.erl
@@ -78,7 +78,7 @@
 %%%========================================================================
 post_data(Method, Headers, {ContentType, Body}) 
   when Method == post; Method == put ->
-    ContentLength = length(Body),
+    ContentLength = integer_to_list(length(Body)),
     NewBody = case Headers#http_request_h.expect of
 		  "100-continue" ->
 		      "";
