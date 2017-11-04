--- lib-python/3/ctypes/__init__.py.orig	2017-10-03 10:53:54 UTC
+++ lib-python/3/ctypes/__init__.py
@@ -345,13 +345,13 @@ class CDLL(object):
         self._FuncPtr = _FuncPtr
 
         if handle is None:
-            if flags & _FUNCFLAG_CDECL:
-                pypy_dll = _ffi.CDLL(name, mode)
-            else:
-                pypy_dll = _ffi.WinDLL(name, mode)
-            self.__pypy_dll__ = pypy_dll
-            handle = int(pypy_dll)
-        self._handle = handle
+            handle = 0
+        if flags & _FUNCFLAG_CDECL:
+            pypy_dll = _ffi.CDLL(name, mode)
+        else:
+            pypy_dll = _ffi.WinDLL(name, mode)
+        self.__pypy_dll__ = pypy_dll
+        self._handle = int(pypy_dll)
 
     def __repr__(self):
         return "<%s '%s', handle %x at 0x%x>" % \
