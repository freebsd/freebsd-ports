--- imageio/core/util.py.orig	2018-09-04 12:21:12 UTC
+++ imageio/core/util.py
@@ -547,6 +547,8 @@ def get_platform():
         plat = "win%i"
     elif sys.platform.startswith("darwin"):
         plat = "osx%i"
+    elif sys.platform.startswith("freebsd"):
+        plat = "freebsd%i"
     else:  # pragma: no cover
         return None
 
