--- setup.py.orig	2026-10-24 22:40:11 UTC
+++ setup.py
@@ -8,7 +8,7 @@ from setuptools.command.build_ext import build_ext
 from setuptools import Extension, setup
 from setuptools.command.build_ext import build_ext
 
-__version__ = "0.7.6"
+__version__ = "0.8.2"
 
 include_dirs = [
     pybind11.get_include(),
