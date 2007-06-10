--- ./setup.py.orig	Thu Feb  8 05:43:56 2007
+++ ./setup.py	Sun Jun 10 22:36:12 2007
@@ -14,12 +14,9 @@
 
 """
 
-from ez_setup import use_setuptools
-use_setuptools()
 
-from setuptools import setup, find_packages
 
-#from distutils.core import setup
+from distutils.core import setup
 
 # Metadata
 PACKAGE_NAME = "vobject"
