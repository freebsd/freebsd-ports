--- setup.py.orig	2025-07-25 08:24:07 UTC
+++ setup.py
@@ -222,10 +222,6 @@ class cmake_build_ext(build_ext):  # noqa: N801
                 cmake_args += [f'-Dpybind11_DIR={pybind11.get_cmake_dir()}']
 
         build_args = ['--config', config]
-        if 'CMAKE_BUILD_PARALLEL_LEVEL' not in os.environ and bool(getattr(self, 'parallel', 0)):
-            build_args += ['--parallel', str(self.parallel)]
-        else:
-            build_args += ['--parallel']
         build_args += ['--target', ext.target, '--']
 
         self.mkpath(str(build_temp))
