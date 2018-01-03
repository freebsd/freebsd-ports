--- rpython/rlib/rvmprof/cintf.py.orig	2017-12-22 10:09:25 UTC
+++ rpython/rlib/rvmprof/cintf.py
@@ -17,7 +17,7 @@ class VMProfPlatformUnsupported(Exceptio
 
 # vmprof works only on x86 for now
 IS_SUPPORTED = detect_cpu.autodetect().startswith('x86')
-if sys.platform == 'win32':
+if sys.platform in ('freebsd10', 'win32'):
     IS_SUPPORTED = False
 
 ROOT = py.path.local(rpythonroot).join('rpython', 'rlib', 'rvmprof')
