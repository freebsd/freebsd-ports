--- whisper.py.orig	2016-01-18 10:45:34 UTC
+++ whisper.py
@@ -48,6 +48,10 @@ if CAN_FALLOCATE: 
   c_off64_t = ctypes.c_int64
   c_off_t = ctypes.c_int
 
+  if os.uname()[0] == 'FreeBSD':
+    # offset type is 64-bit on FreeBSD 32-bit & 64-bit platforms to address files more than 2GB
+    c_off_t = ctypes.c_int64
+
   try:
     _fallocate = libc.posix_fallocate64
     _fallocate.restype = ctypes.c_int
