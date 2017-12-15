--- rpython/rtyper/lltypesystem/ll2ctypes.py.orig	2017-10-03 10:49:20 UTC
+++ rpython/rtyper/lltypesystem/ll2ctypes.py
@@ -1142,7 +1142,7 @@ if ctypes:
     libc_name = get_libc_name()     # Make sure the name is determined during import, not at runtime
     if _FREEBSD:
         RTLD_DEFAULT = -2  # see <dlfcn.h>
-        rtld_default_lib = ctypes.CDLL("RTLD_DEFAULT", handle=RTLD_DEFAULT, **load_library_kwargs)
+        rtld_default_lib = ctypes.CDLL("ld-elf.so.1", handle=RTLD_DEFAULT, **load_library_kwargs)
     # XXX is this always correct???
     standard_c_lib = ctypes.CDLL(libc_name, **load_library_kwargs)
 
@@ -1238,7 +1238,7 @@ def get_ctypes_callable(funcptr, calling
 
     if cfunc is None:
         if _FREEBSD and funcname in ('dlopen', 'fdlopen', 'dlsym', 'dlfunc', 'dlerror', 'dlclose'):
-            cfunc = get_on_lib(rtld_default_lib, funcname)
+            cfunc = rtld_default_lib[funcname]
         else:
             cfunc = get_on_lib(standard_c_lib, funcname)
         # XXX magic: on Windows try to load the function from 'kernel32' too
