--- pypy/module/test_lib_pypy/pyrepl/test_readline.py.orig	2017-10-03 10:53:54 UTC
+++ pypy/module/test_lib_pypy/pyrepl/test_readline.py
@@ -4,7 +4,7 @@ from .infrastructure import sane_term
 
 
 @pytest.mark.skipif("os.name != 'posix' or 'darwin' in sys.platform or "
-                    "'kfreebsd' in sys.platform")
+                    "'freebsd' in sys.platform")
 def test_raw_input():
     import os
     import pty
