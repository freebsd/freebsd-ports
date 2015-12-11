--- commands/python.py.orig	2015-12-11 07:27:06 UTC
+++ commands/python.py
@@ -13,8 +13,6 @@ def get_python_libs():
     if ldv:
         v = ldv
     libs = ['python' + v]
-    if not is_windows():
-        libs.append('dl')
     return libs
 
 def get_python_linker_args():
