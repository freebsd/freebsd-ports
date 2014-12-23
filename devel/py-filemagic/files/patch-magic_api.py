--- magic/api.py.orig	2014-12-23 03:21:58 UTC
+++ magic/api.py
@@ -9,7 +9,7 @@ import ctypes
 import platform
 import warnings
 
-libname = ctypes.util.find_library('magic')
+libname = ctypes.util.find_library('magic') or ctypes.util.find_library('magic1')
 if not libname:
     if platform.system() == 'SunOS':
         libname = 'libmagic.so'
