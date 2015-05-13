--- setup.py.orig	2015-04-11 08:54:57.874207098 +0800
+++ setup.py	2015-04-11 08:55:51.594098942 +0800
@@ -8,14 +8,6 @@
 
 # wow, this is a mixed bag ... I am pretty upset about all of this ...
 setuptools_build_py_module = None
-try:
-    # don't pull it in if we don't have to
-    if 'setuptools' in sys.modules:
-        import setuptools.command.build_py as setuptools_build_py_module
-        from setuptools.command.build_ext import build_ext
-except ImportError:
-    pass
-
 
 class build_ext_nofail(build_ext):
 
