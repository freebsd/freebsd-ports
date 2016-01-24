--- wand/api.py.orig	2015-11-29 19:02:15 UTC
+++ wand/api.py
@@ -179,8 +179,8 @@ try:
     libraries = load_library()
 except (OSError, IOError):
     msg = 'http://docs.wand-py.org/en/latest/guide/install.html'
-    if sys.platform.startswith('freebsd'):
-        msg = 'pkg_add -r'
+    if sys.platform.startswith('dragonfly') or sys.platform.startswith('freebsd'):
+        msg = 'pkg install'
     elif sys.platform == 'win32':
         msg += '#install-imagemagick-on-windows'
     elif sys.platform == 'darwin':
@@ -1390,7 +1390,7 @@ if platform.system() == 'Windows':
 else:
     if platform.system() == 'Darwin':
         libc = ctypes.cdll.LoadLibrary('libc.dylib')
-    elif platform.system() == 'FreeBSD':
+    elif sys.platform.startswith('dragonfly') or sys.platform.startswith('freebsd'):
         libc = ctypes.cdll.LoadLibrary(ctypes.util.find_library('c'))
     else:
         libc = ctypes.cdll.LoadLibrary('libc.so.6')
