--- chai/python2.py.orig	2023-08-20 16:18:50 UTC
+++ chai/python2.py
@@ -1,3 +1,3 @@ def reraise(exc, msg, traceback):
 
 def reraise(exc, msg, traceback):
-    raise exc, msg, traceback
+    raise(exc, msg, traceback)
