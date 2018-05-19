--- parallax/__init__.py.orig	2018-04-19 02:38:57 UTC
+++ parallax/__init__.py
@@ -61,7 +61,7 @@ class Error(BaseException):
     that host.
     """
     def __init__(self, msg, task):
-        super().__init__(self)
+        super(BaseException, self).__init__()
         self.msg = msg
         self.task = task
 
