--- setup.py.orig	2011-07-22 11:50:16.000000000 +0400
+++ setup.py	2011-07-22 11:52:05.000000000 +0400
@@ -2,10 +2,7 @@
 import sys
 import os
 
-try:
-    from setuptools import setup
-except ImportError:
-    from distutils.core import setup
+from distutils.core import setup
 
 if sys.version_info < (2, 4):
     sys.exit("requires python 2.4 and up")
