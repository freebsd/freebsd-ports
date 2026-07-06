--- setup.py.orig	2026-06-10 13:39:49 UTC
+++ setup.py
@@ -21,7 +21,6 @@ from setuptools_rust import build_rust
 from setuptools_rust import RustExtension
 from setuptools_rust import build_rust
 
-import cmake
 
 
 from setuptools import Distribution, Extension, find_packages, setup  # isort: skip
@@ -999,7 +998,7 @@ class CustomBuildExt(build_ext):
 
             install_args = [f"--config {COMPILE_MODE}"]
 
-            cmake_command = (Path(cmake.CMAKE_BIN_DIR) / "cmake").resolve()
+            cmake_command = "cmake"
             subprocess.run([cmake_command, *cmake_args], cwd=cmake_build_dir, check=True)
             subprocess.run([cmake_command, "--build", ".", *build_args], cwd=cmake_build_dir, check=True)
             subprocess.run([cmake_command, "--install", ".", *install_args], cwd=cmake_build_dir, check=True)
@@ -1038,7 +1037,7 @@ class CustomBuildExt(build_ext):
         cmake_build_dir = Path(self.build_lib.replace("lib.", "cmake."), f"{dep.name}_build").resolve()
         cmake_build_dir.mkdir(parents=True, exist_ok=True)
 
-        cmake_command = (Path(cmake.CMAKE_BIN_DIR) / "cmake").resolve()
+        cmake_command = "cmake"
 
         cmake_args = self._base_cmake_args() + [
             f"-S{dep.cmake_dir}",
@@ -1333,9 +1332,7 @@ class CustomBuildExt(build_ext):
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
@@ -1756,14 +1753,12 @@ setup(
     # funcsigs backport required for vendored debtcollector
     cmdclass={
         "build_ext": CustomBuildExt,
-        "build_py": LibraryDownloader,
         "build_rust": CustomBuildRust,
         "clean": CleanLibraries,
         "ext_hashes": ExtensionHashes,
     },
     setup_requires=[
         "cython",
-        "cmake>=3.24.2,<3.28",
         "setuptools-rust<2",
         "patchelf>=0.17.0.0; sys_platform == 'linux'",
     ],
