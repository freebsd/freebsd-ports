- allow to pass a newer setuptools_scm

--- setup.py.orig	2023-11-03 21:27:16 UTC
+++ setup.py
@@ -290,7 +290,7 @@ setup(
         'duckdb-stubs'
     ],
     include_package_data=True,
-    setup_requires=setup_requires + ["setuptools_scm<7.0.0", 'pybind11>=2.6.0'],
+    setup_requires=setup_requires + ["setuptools_scm", 'pybind11>=2.6.0'],
     use_scm_version = setuptools_scm_conf,
     tests_require=['google-cloud-storage', 'mypy', 'pytest'],
     classifiers = [
