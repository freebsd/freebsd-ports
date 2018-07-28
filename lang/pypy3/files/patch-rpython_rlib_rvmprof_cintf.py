--- rpython/rlib/rvmprof/cintf.py.orig	2018-04-24 06:04:29 UTC
+++ rpython/rlib/rvmprof/cintf.py
@@ -17,7 +17,7 @@ class VMProfPlatformUnsupported(Exceptio
 
 # vmprof works only on x86 for now
 IS_SUPPORTED = False
-if sys.platform in ('darwin', 'linux', 'linux2'):
+if sys.platform in ('darwin', 'linux', 'linux2') or sys.platform.startswith('freebsd'):
     try:
         IS_SUPPORTED = detect_cpu.autodetect().startswith('x86')
     except detect_cpu.ProcessorAutodetectError:
