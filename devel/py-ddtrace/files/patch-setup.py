--- setup.py.orig	2025-04-07 19:46:51 UTC
+++ setup.py
@@ -9,7 +9,6 @@ import time
 import tarfile
 import time
 
-import cmake
 from setuptools_rust import Binding
 from setuptools_rust import RustExtension
 
@@ -419,9 +418,7 @@ class CMakeBuild(build_ext):
                 "-DCMAKE_C_FLAGS_%s=-O0" % ext.build_type.upper(),
                 "-DCMAKE_CXX_FLAGS_%s=-O0" % ext.build_type.upper(),
             ]
-        cmake_command = (
-            Path(cmake.CMAKE_BIN_DIR) / "cmake"
-        ).resolve()  # explicitly use the cmake provided by the cmake package
+        cmake_command = "cmake"
         subprocess.run([cmake_command, *cmake_args], cwd=cmake_build_dir, check=True)
         subprocess.run([cmake_command, "--build", ".", *build_args], cwd=cmake_build_dir, check=True)
         subprocess.run([cmake_command, "--install", ".", *install_args], cwd=cmake_build_dir, check=True)
@@ -661,10 +658,9 @@ setup(
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
