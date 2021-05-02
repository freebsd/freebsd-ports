--- setup.py.orig	2021-04-30 20:41:45 UTC
+++ setup.py
@@ -487,11 +487,9 @@ def cmake_available():
 def setup_requires():
     req = [
         "cython>=0.27",
-        "numpy==1.16.* ; python_version < '3.9'",
-        "numpy ; python_version >= '3.9'",
+        "numpy>=1.16",
         "setuptools>=18.0",
         "setuptools_scm>=1.5.4",
-        "wheel>=0.30",
         "pybind11>=2.6.2",
     ]
     # Add cmake requirement if libtiledb is not found and cmake is not available.
@@ -684,7 +682,6 @@ setup(
     setup_requires=setup_requires(),
     install_requires=[
         "numpy>=1.16",
-        "wheel>=0.30",
         "dataclasses ;python_version<'3.7'",
     ],
     packages=find_packages(),
