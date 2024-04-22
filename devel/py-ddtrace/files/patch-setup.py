--- setup.py.orig	2024-04-04 15:25:08 UTC
+++ setup.py
@@ -8,9 +8,7 @@ import tarfile
 import sysconfig
 import tarfile
 
-import cmake
 
-
 from setuptools import Extension, find_packages, setup  # isort: skip
 from setuptools.command.build_ext import build_ext  # isort: skip
 from setuptools.command.build_py import build_py as BuildPyCommand  # isort: skip
@@ -481,10 +479,9 @@ setup(
     # funcsigs backport required for vendored debtcollector
     cmdclass={
         "build_ext": CMakeBuild,
-        "build_py": LibraryDownloader,
         "clean": CleanLibraries,
     },
-    setup_requires=["setuptools_scm[toml]>=4", "cython", "cmake>=3.24.2,<3.28"],
+    setup_requires=["setuptools_scm[toml]>=4", "cython"],
     ext_modules=ext_modules
     + cythonize(
         [
