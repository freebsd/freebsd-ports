Required to let pass the test "ffi_float" successfully

--- tests/unix/ffi_float.py.orig	2021-09-04 05:47:22 UTC
+++ tests/unix/ffi_float.py
@@ -17,7 +17,7 @@ def ffi_open(names):
     raise err
 
 
-libc = ffi_open(("libc.so", "libc.so.0", "libc.so.6", "libc.dylib"))
+libc = ffi_open(("libc.so", "libc.so.0", "libc.so.7", "libc.dylib"))
 
 try:
     strtof = libc.func("f", "strtof", "sp")
