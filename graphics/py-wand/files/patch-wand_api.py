--- wand/api.py.orig	2012-08-15 16:39:28.000000000 +0000
+++ wand/api.py	2012-08-19 10:50:48.000000000 +0000
@@ -273,6 +273,8 @@
 else:
     if platform.system() == 'Darwin':
         libc = ctypes.cdll.LoadLibrary('libc.dylib')
+    elif platform.system() == 'FreeBSD':
+        libc = ctypes.cdll.LoadLibrary(ctypes.util.find_library('c'))
     else:
         libc = ctypes.cdll.LoadLibrary('libc.so.6')
     libc.fdopen.argtypes = [ctypes.c_int, ctypes.c_char_p]
