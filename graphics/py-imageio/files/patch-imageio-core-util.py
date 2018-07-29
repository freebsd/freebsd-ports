--- imageio/core/util.py.orig
+++ imageio/core/util.py
@@ -550,6 +550,8 @@ def get_platform():
         plat = 'win%i'
     elif sys.platform.startswith('darwin'):
         plat = 'osx%i'
+    elif sys.platform.startswith('freebsd'):
+        plat = 'freebsd%i'
     else:  # pragma: no cover
         return None
     
