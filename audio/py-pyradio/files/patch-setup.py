--- setup.py.orig	2022-11-25 15:21:16 UTC
+++ setup.py
@@ -2,7 +2,7 @@
 from os import path as op
 from sys import version_info
 
-from setuptools import setup, find_packages
+from setuptools import setup
 
 from pyradio import version, __project__, __license__
 
@@ -27,8 +27,11 @@ meta = dict(
     author='Ben Dowling',
     author_email='ben.m.dowling@gmail.com',
     url=' http://github.com/coderholic/pyradio',
-    packages=find_packages(),
-    include_package_data=True,
+    packages=['pyradio'],
+    package_dir={'pyradio':'pyradio'},
+    package_data={
+      'pyradio': ['stations.csv', 'config', 'themes/*'],
+    },
     entry_points={
         'console_scripts': [
             'pyradio = pyradio.main:shell',
