--- setup.py.orig	2023-09-18 15:31:38 UTC
+++ setup.py
@@ -568,7 +568,6 @@ setup(
     tests_require=["flake8"],
     cmdclass={
         "build_ext": CMakeBuild,
-        "build_py": LibraryDownloader,
         "clean": CleanLibraries,
     },
     entry_points={
@@ -594,7 +593,7 @@ setup(
         "Programming Language :: Python :: 3.10",
         "Programming Language :: Python :: 3.11",
     ],
-    setup_requires=["setuptools_scm[toml]>=4", "cython<3", "cmake>=3.24.2; python_version>='3.6'"],
+    setup_requires=["setuptools_scm[toml]>=4", "cython<3"],
     ext_modules=ext_modules
     + cythonize(
         [
