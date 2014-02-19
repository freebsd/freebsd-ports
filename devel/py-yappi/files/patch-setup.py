--- ./setup.py.orig	2014-01-06 14:49:25.000000000 +0200
+++ ./setup.py	2014-01-07 13:42:57.722830400 +0200
@@ -1,12 +1,6 @@
 #!/usr/bin/env python
 import os
 import sys
-if sys.version_info >= (3, 0):
-    from distribute_setup import use_setuptools
-else:
-    from ez_setup import use_setuptools
-
-use_setuptools()
 
 from setuptools import setup
 from distutils.core import Extension
@@ -74,7 +68,7 @@
         extra_compile_args = compile_args,
         extra_link_args = link_args,
         )],
-    py_modules =  ["yappi", "distribute_setup", "ez_setup"],
+    py_modules =  ["yappi"],
     entry_points = {
     'console_scripts': [
         'yappi = yappi:main',
