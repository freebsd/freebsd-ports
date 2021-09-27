--- setup.py.orig	2021-09-21 14:40:10 UTC
+++ setup.py
@@ -202,7 +202,7 @@ setup(
         "Programming Language :: Python :: 3.9",
     ],
     use_scm_version={"write_to": "ddtrace/_version.py"},
-    setup_requires=["setuptools_scm[toml]>=4,<6.1", "cython"],
+    setup_requires=["setuptools_scm[toml]>=4", "cython"],
     ext_modules=ext_modules
     + cythonize(
         [
