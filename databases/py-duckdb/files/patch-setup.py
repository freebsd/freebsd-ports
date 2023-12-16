- allow to pass a newer setuptools_scm

--- setup.py.orig	2023-11-14 09:44:27 UTC
+++ setup.py
@@ -349,7 +349,7 @@ setup(
     packages=packages,
     include_package_data=True,
     python_requires='>=3.7.0',
-    setup_requires=setup_requires + ["setuptools_scm<7.0.0", 'pybind11>=2.6.0'],
+    setup_requires=setup_requires + ["setuptools_scm", 'pybind11>=2.6.0'],
     use_scm_version=setuptools_scm_conf,
     tests_require=['google-cloud-storage', 'mypy', 'pytest'],
     classifiers=[
