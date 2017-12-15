--- pypy/module/test_lib_pypy/pyrepl/__init__.py.orig	2017-10-03 10:49:20 UTC
+++ pypy/module/test_lib_pypy/pyrepl/__init__.py
@@ -1,6 +1,3 @@
 import sys
 import lib_pypy.pyrepl
 sys.modules['pyrepl'] = sys.modules['lib_pypy.pyrepl']
-
-if sys.platform.startswith('freebsd'):
-    raise Exception('XXX seems to hangs on FreeBSD9')
