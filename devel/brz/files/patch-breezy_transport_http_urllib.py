--- breezy/transport/http/urllib.py.orig	2021-12-07 02:24:26 UTC
+++ breezy/transport/http/urllib.py
@@ -24,7 +24,6 @@ import base64
 DEBUG = 0
 
 import base64
-import cgi
 import errno
 import os
 import re
@@ -1903,8 +1902,11 @@ class HttpTransport(ConnectedTransport):
             def text(self):
                 if self.status == 204:
                     return None
-                charset = cgi.parse_header(
-                    self._actual.headers['Content-Type'])[1].get('charset')
+                from email.message import EmailMessage
+
+                msg = EmailMessage()
+                msg["content-type"] = self._actual.headers["Content-Type"]
+                charset = msg["content-type"].params.get("charset")
                 if charset:
                     return self.data.decode(charset)
                 else:
