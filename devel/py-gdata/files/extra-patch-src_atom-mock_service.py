--- src/atom/mock_service.py.orig	2008-09-03 23:11:05.000000000 +0200
+++ src/atom/mock_service.py	2009-11-03 21:39:47.358018717 +0100
@@ -34,8 +34,8 @@
 real_request_handler = None
 
 def ConcealValueWithSha(source):
-  import sha
-  return sha.new(source[:-5]).hexdigest()
+  import hashlib 
+  return hashlibsha1.new(source[:-5]).hexdigest()
 
 def DumpRecordings(conceal_func=ConcealValueWithSha):
   if conceal_func:
