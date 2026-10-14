Description: Fix build of 8.0.0: do not read CHANGELOG.rst (missing from the
  sdist) and use find_namespace_packages() for the threema namespace.
  Also drop the wrapt<2 cap: the tree has wrapt 2.x, which the code works
  with (only wrapt.ObjectProxy is used).
Issue ID: https://github.com/threema-ch/threema-msgapi-sdk-python/pull/80
Changeset: none
TODO: Submit upstream; drop the CHANGELOG.rst and namespace hunks once a
  release includes them. Keep the wrapt hunk until upstream relaxes the
  wrapt<2 cap (master still has it).

--- setup.py.orig	2024-08-20 22:00:55 UTC
+++ setup.py
@@ -3,7 +3,7 @@ import os
 import sys
 
 from setuptools import (
-    find_packages,
+    find_namespace_packages,
     setup,
 )
 
@@ -27,7 +27,7 @@ def read(file):
 os.chdir(os.path.normpath(os.path.join(os.path.abspath(__file__), os.pardir)))
 
 # Import long description
-long_description = '\n\n'.join((read('README.rst'), read('CHANGELOG.rst')))
+long_description = read('README.rst')  # CHANGELOG.rst is not in the sdist
 
 # Check python version
 py_version = sys.version_info[:3]
@@ -50,13 +50,13 @@ tests_require = [
 setup(
     name='threema.gateway',
     version=get_version(),
-    packages=find_packages(include=["threema.*"]),
+    packages=find_namespace_packages(include=["threema.*"]),  # threema/ has no __init__.py
     install_requires=[
         'logbook>=1.1.0,<2',
         'libnacl>=1.5.2,<3',
         'click>=8,<9',
         'aiohttp>=3.7.3,<4',
-        'wrapt>=1.10.10,<2',
+        'wrapt>=1.10.10',
     ],
     tests_require=tests_require,
     extras_require={
