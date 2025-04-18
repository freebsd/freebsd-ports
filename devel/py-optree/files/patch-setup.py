--- setup.py.orig	2025-04-06 13:55:44 UTC
+++ setup.py
@@ -211,10 +211,6 @@ class cmake_build_ext(build_ext):  # noqa: N801
                 cmake_args.append(f'-Dpybind11_DIR={pybind11.get_cmake_dir()}')
 
         build_args = ['--config', config]
-        if 'CMAKE_BUILD_PARALLEL_LEVEL' not in os.environ and bool(getattr(self, 'parallel', 0)):
-            build_args.extend(['--parallel', str(self.parallel)])
-        else:
-            build_args.append('--parallel')
 
         build_args.extend(['--target', ext.target, '--'])
 
