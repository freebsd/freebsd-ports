--- ./setup.py.orig	2011-08-07 14:43:22.000000000 +0200
+++ ./setup.py	2011-08-07 19:49:46.126136349 +0200
@@ -4,8 +4,4 @@
 
-try:
-    from setuptools import setup, Extension
-    has_setuptools = True
-except ImportError:
-    from distutils.core import setup, Extension
-    has_setuptools = False
+from distutils.core import setup, Extension
+has_setuptools = False
 from distutils.core import Distribution
