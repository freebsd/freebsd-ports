--- pypy/config/pypyoption.py.orig	2018-07-04 08:38:58 UTC
+++ pypy/config/pypyoption.py
@@ -42,7 +42,7 @@ working_modules.update([
 from rpython.jit.backend import detect_cpu
 try:
     if detect_cpu.autodetect().startswith('x86'):
-        if not sys.platform.startswith('openbsd'):
+        if not (sys.platform.startswith('openbsd') or sys.platform.startswith('freebsd')):
             working_modules.add('_vmprof')
             working_modules.add('faulthandler')
 except detect_cpu.ProcessorAutodetectError:
