--- setup.py.orig	2011-08-25 09:25:25 UTC
+++ setup.py
@@ -22,11 +22,20 @@ import os
 # THE SOFTWARE.
 
 import os
-import imp
+import importlib.util
+import importlib.machinery
 from setuptools import setup
 
 PKG_DIR = 'pathtools'
-version = imp.load_source('version',
+
+def load_source(modname, filename):
+    loader = importlib.machinery.SourceFileLoader(modname, filename)
+    spec = importlib.util.spec_from_file_location(modname, filename, loader=loader)
+    module = importlib.util.module_from_spec(spec)
+    loader.exec_module(module)
+    return module
+
+version = load_source('version',
                           os.path.join(PKG_DIR, 'version.py'))
 
 def read_file(filename):
