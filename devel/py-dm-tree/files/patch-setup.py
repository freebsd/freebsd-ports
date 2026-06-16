-- Add pybind11_DIR to CMake arguments so that find_package(pybind11)
-- can locate the system pybind11 installation. Without this, CMake's
-- FetchContent falls back to downloading pybind11 from the internet,
-- which fails in offline build environments like poudriere.

--- setup.py.orig	2026-06-16 03:31:42 UTC
+++ setup.py
@@ -82,7 +82,8 @@ class BuildCMakeExtension(build_ext.build_ext):
         f'-DPython3_ROOT_DIR={sys.prefix}',
         f'-DPython3_EXECUTABLE={sys.executable}',
         f'-DCMAKE_LIBRARY_OUTPUT_DIRECTORY={extension_dir}',
-        f'-DCMAKE_BUILD_TYPE={build_cfg}'
+        f'-DCMAKE_BUILD_TYPE={build_cfg}',
+        f'-Dpybind11_DIR={sysconfig.get_paths()["purelib"]}/pybind11/share/cmake/pybind11'
     ]
     if platform.system() != 'Windows':
       cmake_args.extend([
