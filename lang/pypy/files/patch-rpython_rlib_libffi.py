--- rpython/rlib/libffi.py.orig	2017-10-03 10:49:20 UTC
+++ rpython/rlib/libffi.py
@@ -434,11 +434,12 @@ class Func(AbstractFuncPtr):
 
 # XXX: it partially duplicate the code in clibffi.py
 class CDLL(object):
-    def __init__(self, libname, mode=-1):
+    def __init__(self, libname, mode=-1, lib=0):
         """Load the library, or raises DLOpenError."""
-        self.lib = rffi.cast(DLLHANDLE, 0)
-        with rffi.scoped_str2charp(libname) as ll_libname:
-            self.lib = dlopen(ll_libname, mode)
+        self.lib = rffi.cast(DLLHANDLE, lib)
+        if lib == 0:
+            with rffi.scoped_str2charp(libname) as ll_libname:
+                self.lib = dlopen(ll_libname, mode)
 
     def __del__(self):
         if self.lib:
