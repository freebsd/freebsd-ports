--- gevent/_util_py2.py.orig	2015-12-11 14:42:42 UTC
+++ gevent/_util_py2.py
@@ -5,4 +5,4 @@ __all__ = ['reraise']
 
 
 def reraise(type, value, tb):
-    raise type, value, tb
+    raise type(value).with_traceback(tb)
