--- pypy/module/termios/test/test_termios.py.orig	2017-10-03 10:49:20 UTC
+++ pypy/module/termios/test/test_termios.py
@@ -7,9 +7,6 @@ from rpython.tool.udir import udir
 if os.name != 'posix':
     py.test.skip('termios module only available on unix')
 
-if sys.platform.startswith('freebsd'):
-    raise Exception('XXX seems to hangs on FreeBSD9')
-
 class TestTermios(object):
     def setup_class(cls):
         try:
