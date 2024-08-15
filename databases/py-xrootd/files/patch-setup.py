--- setup.py.orig	2024-07-01 06:56:54 UTC
+++ setup.py
@@ -118,7 +118,7 @@ class CMakeBuild(build_ext):
                 os.makedirs(self.build_temp)
 
             check_call([cmake, ext.src, '-B', self.build_temp] + cmake_args)
-            check_call([cmake, '--build', self.build_temp, '--parallel'])
+            check_call([cmake, '--build', self.build_temp])
 
 version = get_version()
 
