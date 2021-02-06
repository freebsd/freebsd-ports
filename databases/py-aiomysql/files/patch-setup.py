--- setup.py.orig	2020-11-26 16:45:41 UTC
+++ setup.py
@@ -4,7 +4,7 @@ import sys
 from setuptools import setup, find_packages
 
 
-install_requires = ['PyMySQL>=0.9,<=0.9.3']
+install_requires = ['PyMySQL>=0.9']
 
 PY_VER = sys.version_info
 
