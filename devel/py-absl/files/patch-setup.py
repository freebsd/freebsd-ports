--- setup.py.orig	2019-03-15 00:56:19.000000000 +0300
+++ setup.py	2021-10-28 14:41:48.002012000 +0300
@@ -29,10 +29,6 @@
   use_setuptools()
   import setuptools
 
-py_version = platform.python_version_tuple()
-if py_version < ('2', '7') or py_version[0] == '3' and py_version < ('3', '4'):
-  raise RuntimeError('Python version 2.7 or 3.4+ is required.')
-
 INSTALL_REQUIRES = [
     'six',
 ]
