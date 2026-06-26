--- setup.py.orig	2021-05-21 16:12:34 UTC
+++ setup.py
@@ -3,7 +3,7 @@ import os
 
 from setuptools import setup, find_packages
 import os
-import imp
+import importlib
 import traceback
 
 
@@ -11,14 +11,14 @@ def get_version():
     """Get version and version_info without importing the entire module."""
 
     path = os.path.join(os.path.dirname(__file__), 'pep562')
-    fp, pathname, desc = imp.find_module('__init__', [path])
+    pathname = os.path.join(path, '__init__.py')
     try:
-        module = imp.load_module('__init__', fp, pathname, desc)
+        spec = importlib.util.spec_from_file_location('pep562', pathname)
+        module = importlib.util.module_from_spec(spec)
+        spec.loader.exec_module(module)
         return module.__version__, module.__version_info__._get_dev_status()
     except Exception:
         print(traceback.format_exc())
-    finally:
-        fp.close()
 
 
 def get_requirements(req):
