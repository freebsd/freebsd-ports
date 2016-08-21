--- pypy/module/_cffi_backend/misc.py.orig	2016-06-14 07:46:04 UTC
+++ pypy/module/_cffi_backend/misc.py
@@ -253,6 +253,7 @@ _is_nonnull_longdouble = rffi.llexternal
     sandboxsafe=True)
 
 # split here for JIT backends that don't support floats/longlongs/etc.
+@jit.dont_look_inside
 def is_nonnull_longdouble(cdata):
     return _is_nonnull_longdouble(read_raw_longdouble_data(cdata))
 def is_nonnull_float(cdata, size):
