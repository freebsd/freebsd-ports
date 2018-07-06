--- pypy/config/pypyoption.py.orig	2018-07-04 10:31:39 UTC
+++ pypy/config/pypyoption.py
@@ -46,7 +46,7 @@ working_modules.update([
 from rpython.jit.backend import detect_cpu
 try:
     if detect_cpu.autodetect().startswith('x86'):
-        if not sys.platform.startswith('openbsd'):
+        if not (sys.platform.startswith('openbsd') or sys.platform.startswith('freebsd')):
             working_modules.add('_vmprof')
             working_modules.add('faulthandler')
 except detect_cpu.ProcessorAutodetectError:
