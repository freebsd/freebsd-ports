Use 'distribute' package provides by ports tree.

--- ./setup.py.orig	2013-10-11 00:08:24.000000000 +0000
+++ ./setup.py	2013-10-12 21:59:11.000000000 +0000
@@ -1,8 +1,6 @@
 #!/usr/bin/env python
-from distribute_setup import use_setuptools
-use_setuptools()
 
-from setuptools import setup
+from distutils.core import setup
 import xmltodict
 
 setup(name='xmltodict',
@@ -30,5 +28,5 @@
           'Topic :: Text Processing :: Markup :: XML',
       ],
       py_modules=['xmltodict'],
-      setup_requires=['nose>=1.0', 'coverage'],
+      #setup_requires=['nose>=1.0', 'coverage'],
       )
