--- setup.py.orig	2023-07-25 21:04:28 UTC
+++ setup.py
@@ -557,7 +557,6 @@ setup(
     tests_require=["flake8"],
     cmdclass={
         "build_ext": CMakeBuild,
-        "build_py": LibraryDownloader,
         "clean": CleanLibraries,
     },
     entry_points={
@@ -584,7 +583,7 @@ setup(
         "Programming Language :: Python :: 3.11",
     ],
     use_scm_version={"write_to": "ddtrace/_version.py"},
-    setup_requires=["setuptools_scm[toml]>=4", "cython<3", "cmake>=3.24.2; python_version>='3.6'"],
+    setup_requires=["setuptools_scm[toml]>=4", "cython<3"],
     ext_modules=ext_modules
     + cythonize(
         [
