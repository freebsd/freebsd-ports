--- setup.py.orig	2025-03-01 19:39:44 UTC
+++ setup.py
@@ -119,10 +119,6 @@ class cmake_build_ext(build_ext):  # noqa: N801
                 cmake_args.append(f'-Dpybind11_DIR={pybind11.get_cmake_dir()}')
 
         build_args = ['--config', config]
-        if 'CMAKE_BUILD_PARALLEL_LEVEL' not in os.environ and bool(getattr(self, 'parallel', 0)):
-            build_args.extend(['--parallel', str(self.parallel)])
-        else:
-            build_args.append('--parallel')
 
         build_args.extend(['--target', ext.target, '--'])
 
@@ -138,7 +134,7 @@ class cmake_build_ext(build_ext):  # noqa: N801
             with unset_python_path():
                 self.spawn([cmake, '--version'])  # cmake in the parent virtual environment
 
-        self.mkpath(build_temp)
+        self.mkpath(str(build_temp))
         with spawn_context():
             self.spawn([cmake, '-S', str(ext.source_dir), '-B', str(build_temp), *cmake_args])
             self.spawn([cmake, '--build', str(build_temp), *build_args])
