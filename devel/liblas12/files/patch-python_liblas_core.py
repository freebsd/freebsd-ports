--- python/liblas/core.py.orig	2009-10-02 17:48:41 UTC
+++ python/liblas/core.py
@@ -131,7 +131,7 @@ elif os.name == 'posix':
         lib_name = 'liblas.dylib'
         free = ctypes.CDLL(find_library('libc')).free
     else:
-        lib_name = 'liblas.so'
+        lib_name = 'liblas12.so'
         free = ctypes.CDLL(find_library('libc.so.6')).free
     las = ctypes.CDLL(lib_name)
 else:
