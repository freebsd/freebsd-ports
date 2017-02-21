--- mypy/fastparse2.py.orig	2017-02-15 15:30:42 UTC
+++ mypy/fastparse2.py
@@ -43,7 +43,7 @@ from mypy.fastparse import TypeConverter
 
 try:
     from typed_ast import ast27
-    from typed_ast import ast35
+    from typed_ast import ast3 as ast35
 except ImportError:
     if sys.version_info.minor > 2:
         print('You must install the typed_ast package before you can run mypy'
