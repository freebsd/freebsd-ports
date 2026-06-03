--- qutip/settings.py.orig	2026-05-25 20:41:05 UTC
+++ qutip/settings.py
@@ -154,6 +154,8 @@ def _find_mkl():
         ext = ".dll"
     elif plat in ['linux2', 'linux']:
         ext = ".so"
+    elif plat.startswith('freebsd'):
+        ext = ".so"
     else:
         raise Exception('Unknown platfrom.')
 
