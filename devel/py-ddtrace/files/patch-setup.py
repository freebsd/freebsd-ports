--- setup.py.orig	2023-09-26 19:15:41 UTC
+++ setup.py
@@ -567,7 +567,6 @@ setup(
     tests_require=["flake8"],
     cmdclass={
         "build_ext": CMakeBuild,
-        "build_py": LibraryDownloader,
         "clean": CleanLibraries,
     },
     entry_points={
@@ -593,7 +592,7 @@ setup(
         "Programming Language :: Python :: 3.10",
         "Programming Language :: Python :: 3.11",
     ],
-    setup_requires=["setuptools_scm[toml]>=4,<8", "cython<3", "cmake>=3.24.2; python_version>='3.6'"],
+    setup_requires=["setuptools_scm[toml]>=4,<8", "cython<3"],
     ext_modules=ext_modules
     + cythonize(
         [
