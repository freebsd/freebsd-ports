--- setup.py.orig	2021-04-11 12:39:58 UTC
+++ setup.py
@@ -517,11 +517,9 @@ def cmake_available():
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
@@ -721,7 +719,6 @@ setup(
     setup_requires=setup_requires(),
     install_requires=[
         "numpy>=1.16",
-        "wheel>=0.30",
         "dataclasses ;python_version<'3.7'",
     ],
     tests_require=TESTS_REQUIRE,
