Prevents runtime issues with nVidia drivers

--- qt/aqt/__init__.py.orig	2023-04-15 12:54:44 UTC
+++ qt/aqt/__init__.py
@@ -369,7 +369,7 @@ def setupGL(pm: aqt.profiles.ProfileManager) -> None:
     driver = pm.video_driver()
 
     # work around pyqt loading wrong GL library
-    if is_lin:
+    if is_lin and not sys.platform.startswith("freebsd"):
         import ctypes
 
         ctypes.CDLL("libGL.so.1", ctypes.RTLD_GLOBAL)
