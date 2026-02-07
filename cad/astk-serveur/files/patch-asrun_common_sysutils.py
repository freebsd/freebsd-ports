--- asrun/common/sysutils.py.orig	2017-07-13 07:40:52 UTC
+++ asrun/common/sysutils.py
@@ -83,7 +83,7 @@ def on_mac():
 
 def on_linux():
     """Tell if it's running on a linux platform"""
-    return not on_windows()
+    return sys.platform in ("linux")
 
 def on_64bits():
     """Tell if it's running on a 64 bits platform"""
@@ -212,7 +212,7 @@ class FileName(object):
         and fill properties = user, passwd, mach, path
         """
         # windows : only work on local files
-        if not on_linux():
+        if on_windows():
             self.path = pathname
             return
         # posix
