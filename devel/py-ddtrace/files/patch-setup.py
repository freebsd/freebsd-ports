--- setup.py.orig	2021-10-28 20:18:41 UTC
+++ setup.py
@@ -203,7 +203,7 @@ setup(
         "Programming Language :: Python :: 3.10",
     ],
     use_scm_version={"write_to": "ddtrace/_version.py"},
-    setup_requires=["setuptools_scm[toml]>=4,<6.1", "cython"],
+    setup_requires=["setuptools_scm[toml]>=4", "cython"],
     ext_modules=ext_modules
     + cythonize(
         [
