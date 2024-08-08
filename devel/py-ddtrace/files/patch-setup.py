--- setup.py.orig	2024-08-01 21:44:34 UTC
+++ setup.py
@@ -8,7 +8,6 @@ import tarfile
 import sysconfig
 import tarfile
 
-import cmake
 from setuptools_rust import Binding
 from setuptools_rust import RustExtension
 
@@ -495,10 +494,9 @@ setup(
     # funcsigs backport required for vendored debtcollector
     cmdclass={
         "build_ext": CMakeBuild,
-        "build_py": LibraryDownloader,
         "clean": CleanLibraries,
     },
-    setup_requires=["setuptools_scm[toml]>=4", "cython", "cmake>=3.24.2,<3.28", "setuptools-rust"],
+    setup_requires=["setuptools_scm[toml]>=4", "cython", "setuptools-rust"],
     ext_modules=ext_modules
     + cythonize(
         [
