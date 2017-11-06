--- pypy/module/_rawffi/alt/interp_funcptr.py.orig	2017-10-03 10:49:20 UTC
+++ pypy/module/_rawffi/alt/interp_funcptr.py
@@ -314,7 +314,7 @@ W_FuncPtr.typedef = TypeDef(
 # ========================================================================
 
 class W_CDLL(W_Root):
-    def __init__(self, space, name, mode):
+    def __init__(self, space, name, mode, handle):
         self.flags = libffi.FUNCFLAG_CDECL
         self.space = space
         if name is None:
@@ -322,7 +322,7 @@ class W_CDLL(W_Root):
         else:
             self.name = name
         try:
-            self.cdll = libffi.CDLL(name, mode)
+            self.cdll = libffi.CDLL(name, mode, handle)
         except DLOpenError as e:
             raise wrap_dlopenerror(space, e, self.name)
         except OSError as e:
@@ -344,9 +344,9 @@ class W_CDLL(W_Root):
     def getidentifier(self, space):
         return space.newint(self.cdll.getidentifier())
 
-@unwrap_spec(name='fsencode_or_none', mode=int)
-def descr_new_cdll(space, w_type, name, mode=-1):
-    return W_CDLL(space, name, mode)
+@unwrap_spec(name='fsencode_or_none', mode=int, handle=int)
+def descr_new_cdll(space, w_type, name, mode=-1, handle=0):
+    return W_CDLL(space, name, mode, handle)
 
 
 W_CDLL.typedef = TypeDef(
@@ -359,13 +359,13 @@ W_CDLL.typedef = TypeDef(
     )
 
 class W_WinDLL(W_CDLL):
-    def __init__(self, space, name, mode):
-        W_CDLL.__init__(self, space, name, mode)
+    def __init__(self, space, name, mode, handle):
+        W_CDLL.__init__(self, space, name, mode, handle)
         self.flags = libffi.FUNCFLAG_STDCALL
 
-@unwrap_spec(name='fsencode_or_none', mode=int)
-def descr_new_windll(space, w_type, name, mode=-1):
-    return W_WinDLL(space, name, mode)
+@unwrap_spec(name='fsencode_or_none', mode=int, handle=int)
+def descr_new_windll(space, w_type, name, mode=-1, handle=0):
+    return W_WinDLL(space, name, mode, handle)
 
 
 W_WinDLL.typedef = TypeDef(
@@ -380,4 +380,4 @@ W_WinDLL.typedef = TypeDef(
 # ========================================================================
 
 def get_libc(space):
-    return W_CDLL(space, get_libc_name(), -1)
+    return W_CDLL(space, get_libc_name(), -1, 0)
