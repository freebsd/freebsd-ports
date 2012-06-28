--- ./setup.py.orig	2012-06-15 22:18:19.000000000 +1000
+++ ./setup.py	2012-06-15 22:18:34.000000000 +1000
@@ -38,10 +38,7 @@
 
 import os
 import sys
-try:
-    from setuptools import setup
-except ImportError:
-    from distutils.core import setup
+from distutils.core import setup
 
 name = 'pyftpdlib'
 version = '0.7.0'
