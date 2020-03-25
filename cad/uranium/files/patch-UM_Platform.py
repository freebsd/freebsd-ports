--- UM/Platform.py.orig	2020-03-06 21:26:24 UTC
+++ UM/Platform.py
@@ -40,7 +40,7 @@ class Platform:
     __platform_type = PlatformType.Other
     if sys.platform == "win32":
         __platform_type = PlatformType.Windows
-    elif sys.platform == "linux":
+    elif (sys.platform == "linux" or "bsd" in sys.platform):
         __platform_type = PlatformType.Linux
     elif sys.platform == "darwin":
         __platform_type = PlatformType.OSX
