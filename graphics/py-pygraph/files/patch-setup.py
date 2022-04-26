--- setup.py.orig	2017-10-31 16:41:33 UTC
+++ setup.py
@@ -1,6 +1,6 @@
 from setuptools import find_packages, setup
 
-EXCLUDE_FROM_PACKAGES = []
+EXCLUDE_FROM_PACKAGES = ['tests']
 
 setup(
     name='PyGraph',
