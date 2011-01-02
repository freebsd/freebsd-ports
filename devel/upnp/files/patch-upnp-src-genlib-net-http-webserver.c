--- upnp/src/genlib/net/http/webserver.c.orig
+++ upnp/src/genlib/net/http/webserver.c
@@ -1262,7 +1262,7 @@ static int process_request(
 			// Content-Range: bytes 222-3333/4000  HTTP_PARTIAL_CONTENT
 			// Transfer-Encoding: chunked
 			if (http_MakeMessage(headers, resp_major, resp_minor,
-			    "R" "TLD" "s" "tcS" "b" "Xc" "sCc",
+			    "R" "TLD" "s" "tcS" "Xc" "sCc",
 			    HTTP_OK,	// status code
 			    finfo.content_type,	// content type
 			    RespInstr,	// language info
