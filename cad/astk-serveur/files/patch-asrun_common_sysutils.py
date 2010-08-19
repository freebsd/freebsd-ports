--- ./asrun/common/sysutils.py.orig	2010-07-07 18:18:08.000000000 +0200
+++ ./asrun/common/sysutils.py	2010-08-13 19:24:59.000000000 +0200
@@ -67,7 +67,7 @@
 
 def on_linux():
     """Tell if it's running on a linux platform"""
-    return not on_windows()
+    return sys.platform in ("linux")
 
 def on_64bits():
     """Tell if it's running on a 64 bits platform"""
@@ -125,7 +125,7 @@
         and fill properties = user, passwd, mach, path
         """
         # windows : only work on local files
-        if not on_linux():
+        if on_windows():
             self.path = pathname
         # posix
         if type(pathname) not in (str, unicode):
