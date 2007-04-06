--- setup.py.orig	Thu Apr  5 23:51:45 2007
+++ setup.py	Thu Apr  5 23:51:58 2007
@@ -2,8 +2,8 @@
 
 import os
 import sys
-import ez_setup; ez_setup.use_setuptools()
-from setuptools import setup, Extension
+from distutils.core import setup
+from distutils.extension import Extension
 
 if sys.version_info < (2, 3):
     raise Error, "Python-2.3 or newer is required"
