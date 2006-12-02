
$FreeBSD$

--- setup.py.orig
+++ setup.py
@@ -1,12 +1,13 @@
 # bootstrap setuptools if necessary
-from ez_setup import use_setuptools
-use_setuptools()
+#from ez_setup import use_setuptools
+#use_setuptools()
 
 import os
 
 execfile(os.path.join("kid", "release.py"))
 
-from setuptools import setup, find_packages
+#from setuptools import setup, find_packages
+from distutils.core import *
 
 install_requires = []
 try:
