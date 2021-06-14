--- setup.py.orig	2021-06-08 20:19:16 UTC
+++ setup.py
@@ -489,12 +489,9 @@ def cmake_available():
 def setup_requires():
     req = [
         "cython>=0.27",
-        "numpy==1.16.* ; python_version < '3.9' and 'arm' not in platform_machine",
-        "numpy ; python_version >= '3.9' and 'arm' not in platform_machine",
-        "numpy ; 'arm' in platform_machine",
+        "numpy>=1.16",
         "setuptools>=18.0",
         "setuptools_scm>=1.5.4",
-        "wheel>=0.30",
         "pybind11>=2.6.2",
     ]
     # Add cmake requirement if libtiledb is not found and cmake is not available.
@@ -687,7 +684,6 @@ setup(
     setup_requires=setup_requires(),
     install_requires=[
         "numpy>=1.16",
-        "wheel>=0.30",
         "contextvars ;python_version<'3.7'",
         "dataclasses ;python_version<'3.7'",
     ],
