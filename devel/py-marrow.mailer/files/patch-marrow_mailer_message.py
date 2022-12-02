# base64.encodestring()
# Deprecated alias of encodebytes(), removed in Python 3.9
--- marrow/mailer/message.py.orig	2019-09-16 00:05:09 UTC
+++ marrow/mailer/message.py
@@ -305,7 +305,7 @@ class Message(object):
 		else:
 			raise TypeError("Unable to read attachment contents")
 		
-		part.set_payload(base64.encodestring(value))
+		part.set_payload(base64.encodebytes(value))
 
 		if not filename:
 			filename = name
