--- breezy/transport/http/response.py.orig	2021-12-07 02:24:26 UTC
+++ breezy/transport/http/response.py
@@ -21,7 +21,6 @@ responses.
 responses.
 """
 
-import cgi
 from io import BytesIO
 import os
 import http.client as http_client
@@ -383,10 +382,15 @@ def handle_response(url, code, getheader, data):
         # being of type 'application/octet-stream' as per RFC2616 section
         # 7.2.1.
         # Therefore it is obviously not multipart
-        content_type = getheader('content-type', 'application/octet-stream')
-        mimetype, options = cgi.parse_header(content_type)
+        content_type = getheader("content-type", "application/octet-stream")
+        from email.message import EmailMessage
+
+        msg = EmailMessage()
+        msg["content-type"] = content_type
+        params = msg["content-type"].params
+        mimetype = msg.get_content_type()
         if mimetype == 'multipart/byteranges':
-            rfile.set_boundary(options['boundary'].encode('ascii'))
+            rfile.set_boundary(params['boundary'].encode('ascii'))
         else:
             # A response to a range request, but not multipart
             content_range = getheader('content-range', None)
