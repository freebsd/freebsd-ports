--- rpython/rlib/rvmprof/cintf.py.orig	2017-10-03 10:49:20 UTC
+++ rpython/rlib/rvmprof/cintf.py
@@ -47,7 +47,10 @@ else:
     # Guessing a BSD-like Unix platform
     compile_extra += ['-DVMPROF_UNIX']
     compile_extra += ['-DVMPROF_MAC']
-    _libs = []
+    if sys.platform.startswith('freebsd'):
+        _libs = ['unwind']
+    else:
+        _libs = []
 
 
 eci_kwds = dict(
