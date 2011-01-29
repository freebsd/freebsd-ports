--- ./setup.py.orig	2010-10-23 22:50:04.000000000 +0200
+++ ./setup.py	2011-01-27 02:30:39.000000000 +0100
@@ -27,13 +27,10 @@
 from distutils import log
 from distutils.command.build_ext import build_ext as _build_ext
 
-try:
-    from setuptools import setup, Extension
-except ImportError:
-    from ez_setup import use_setuptools
-    use_setuptools()
+from ez_setup import use_setuptools
+use_setuptools()
 
-    from setuptools import setup, Extension
+from setuptools import setup, Extension
 
 class UnsupportedPlatformWarning(Warning):
     pass
