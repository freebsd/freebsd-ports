--- setup.py.orig	2010-10-10 00:49:45.379628041 +0800
+++ setup.py	2010-10-10 00:49:58.743854117 +0800
@@ -22,10 +22,7 @@
 import glob
 from os.path import join, isdir, abspath, basename, exists, dirname
 
-try:
-    from setuptools import Extension, setup
-except ImportError:
-    from distutils.core import Extension, setup
+from distutils.core import Extension, setup
 from distutils.command import build_ext
 
 __version__ = re.search("__version__\s*=\s*'(.*)'", open('gevent/__init__.py').read(), re.M).group(1)
