--- setup.py.orig	2020-07-12 18:16:03 UTC
+++ setup.py
@@ -5,7 +5,7 @@ from setuptools import setup, find_packages
 
 install_requires = []
 tests_require = ["coverage", "flake8", "pexpect", "wheel"]
-importlib_backport_requires = ["importlib-metadata >= 0.23, < 2"]
+importlib_backport_requires = ["importlib-metadata >= 0.23"]
 
 setup(
     name='argcomplete',
