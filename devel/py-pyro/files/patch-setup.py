--- setup.py.orig	2011-06-27 12:36:55.000000000 +0400
+++ setup.py	2011-06-27 12:40:48.000000000 +0400
@@ -1,9 +1,5 @@
 import sys
-try:
-    # try setuptools first, to get access to build_sphinx command
-    from setuptools import setup
-except ImportError:
-    from distutils.core import setup
+from distutils.core import setup
 
 if __name__ == '__main__' :
     sys.path.insert(0, "src")
