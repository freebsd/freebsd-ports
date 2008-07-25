--- setup.py.orig	2008-07-21 23:42:54.000000000 +0800
+++ setup.py	2008-07-21 23:43:00.000000000 +0800
@@ -1,5 +1,5 @@
-from ez_setup import use_setuptools
-use_setuptools()
+#from ez_setup import use_setuptools
+#use_setuptools()
 from setuptools import setup, find_packages
 from distutils.command.build_py import build_py as _build_py
 from setuptools.command.sdist import sdist as _sdist
