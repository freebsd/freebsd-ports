--- wand/api.py.orig	2016-05-31 16:40:51 UTC
+++ wand/api.py
@@ -180,8 +180,8 @@ try:
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
@@ -1418,7 +1418,7 @@ else:
         except OSError:
             # In case of El Capitan SIP
             libc = ctypes.cdll.LoadLibrary('/usr/lib/libc.dylib')
-    elif platform.system() == 'FreeBSD':
+    elif sys.platform.startswith('dragonfly') or sys.platform.startswith('freebsd'):
         libc = ctypes.cdll.LoadLibrary(ctypes.util.find_library('c'))
     else:
         libc = ctypes.cdll.LoadLibrary('libc.so.6')
