--- lib-python/2.7/ctypes/__init__.py.orig	2017-10-03 10:49:20 UTC
+++ lib-python/2.7/ctypes/__init__.py
@@ -360,14 +360,15 @@ class CDLL(object):
         self._FuncPtr = _FuncPtr
 
         if handle is None:
-            if flags & _FUNCFLAG_CDECL:
-                pypy_dll = _ffi.CDLL(name, mode)
-            else:
-                pypy_dll = _ffi.WinDLL(name, mode)
-            self.__pypy_dll__ = pypy_dll
-            handle = int(pypy_dll)
-            if _sys.maxint > 2 ** 32:
-                handle = int(handle)   # long -> int
+            handle = 0
+        if flags & _FUNCFLAG_CDECL:
+            pypy_dll = _ffi.CDLL(name, mode, handle)
+        else:
+            pypy_dll = _ffi.WinDLL(name, mode, handle)
+        self.__pypy_dll__ = pypy_dll
+        handle = int(pypy_dll)
+        if _sys.maxint > 2 ** 32:
+            handle = int(handle)   # long -> int
         self._handle = handle
 
     def __repr__(self):
