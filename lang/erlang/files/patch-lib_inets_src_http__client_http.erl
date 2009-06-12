
$FreeBSD$

--- lib/inets/src/http_client/http.erl.orig
+++ lib/inets/src/http_client/http.erl
@@ -293,6 +293,8 @@
     case {Sync, Stream} of
 	{true, self} ->
 	    {error, streaming_error};
+	{true, {self,once}} ->
+	    {error, streaming_error};
 	_ ->
 	    RecordHeaders = header_record(NewHeaders, #http_request_h{}, 
 					  Host, Version),
