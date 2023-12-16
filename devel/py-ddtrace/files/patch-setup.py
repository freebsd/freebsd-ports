--- setup.py.orig	2023-11-13 15:24:48 UTC
+++ setup.py
@@ -566,7 +566,6 @@ setup(
     tests_require=["flake8"],
     cmdclass={
         "build_ext": CMakeBuild,
-        "build_py": LibraryDownloader,
         "clean": CleanLibraries,
     },
     entry_points={
@@ -593,7 +592,7 @@ setup(
         "Programming Language :: Python :: 3.11",
         "Programming Language :: Python :: 3.12",
     ],
-    setup_requires=["setuptools_scm[toml]>=4", "cython", "cmake>=3.24.2"],
+    setup_requires=["setuptools_scm[toml]>=4", "cython"],
     ext_modules=ext_modules
     + cythonize(
         [
