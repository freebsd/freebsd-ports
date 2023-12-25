--- setup.py.orig	2023-11-07 06:45:50 UTC
+++ setup.py
@@ -67,15 +67,6 @@ class cmake_build_ext(build_ext):  # noqa: N801
             pass
 
         build_args = ['--config', config]
-        if (
-            'CMAKE_BUILD_PARALLEL_LEVEL' not in os.environ
-            and hasattr(self, 'parallel')
-            and self.parallel
-        ):
-            build_args.extend(['--parallel', str(self.parallel)])
-        else:
-            build_args.append('--parallel')
-
         build_args.extend(['--target', ext.target, '--'])
 
         try:
