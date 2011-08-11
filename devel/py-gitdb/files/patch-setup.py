--- setup.py.orig	2011-07-05 18:59:59.000000000 +0400
+++ setup.py	2011-07-14 22:37:09.000000000 +0400
@@ -7,13 +7,6 @@
 
 # wow, this is a mixed bag ... I am pretty upset about all of this ... 
 setuptools_build_py_module = None
-try:
-	# don't pull it in if we don't have to
-	if 'setuptools' in sys.modules: 
-		import setuptools.command.build_py as setuptools_build_py_module
-		from setuptools.command.build_ext import build_ext
-except ImportError:
-	pass
 
 class build_ext_nofail(build_ext):
 	"""Doesn't fail when build our optional extensions"""
