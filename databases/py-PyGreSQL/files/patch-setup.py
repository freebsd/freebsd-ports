--- ./setup.py.orig	2013-01-03 16:46:09.000000000 +0400
+++ ./setup.py	2013-01-03 21:16:42.000000000 +0400
@@ -47,10 +47,10 @@
 
 import os
 import platform
-try:
-    from setuptools import setup
-except ImportError:
-    from distutils.core import setup
+#try:
+#    from setuptools import setup
+#except ImportError:
+from distutils.core import setup
 from distutils.extension import Extension
 from distutils.command.build_ext import build_ext
 from distutils.ccompiler import get_default_compiler
