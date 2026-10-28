-- remove tests from installed packages

--- setup.py.orig	2025-10-07 14:57:08 UTC
+++ setup.py
@@ -12,6 +12,7 @@ try:
 try:
     from setuptools import setup
     from setuptools import Command
+    from setuptools import find_packages
 except ImportError:
     from distutils.core import setup
     from distutils.core import Command
@@ -41,4 +42,5 @@ with open(os.path.join(project_name, 'version.py'), 'r
 
 
 # Project setup
-setup(name=project_name, version=project_version)
+setup(name=project_name, version=project_version,
+    packages=find_packages(exclude=["tests", "tests.*"]))
