Required to let pass the test "ffi_callback" successfully

--- tests/unix/ffi_callback.py.orig	2021-09-04 05:46:01 UTC
+++ tests/unix/ffi_callback.py
@@ -16,7 +16,7 @@ def ffi_open(names):
     raise err
 
 
-libc = ffi_open(("libc.so", "libc.so.0", "libc.so.6", "libc.dylib"))
+libc = ffi_open(("libc.so", "libc.so.0", "libc.so.7", "libc.dylib"))
 
 qsort = libc.func("v", "qsort", "piip")
 
