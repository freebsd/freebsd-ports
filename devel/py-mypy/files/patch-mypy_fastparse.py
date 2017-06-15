--- mypy/fastparse.py.orig	2017-02-15 15:30:38 UTC
+++ mypy/fastparse.py
@@ -26,7 +26,7 @@ from mypy import experiments
 from mypy.errors import Errors
 
 try:
-    from typed_ast import ast35
+    from typed_ast import ast3 as ast35
 except ImportError:
     if sys.version_info.minor > 2:
         print('You must install the typed_ast package before you can run mypy'
