- workaround for https://github.com/sbmlteam/python-libsbml/issues/36

--- setup.py.orig	2023-05-25 10:49:17 UTC
+++ setup.py
@@ -248,7 +248,7 @@ class CMakeBuild(build_ext):
                              '-DWITH_LIBXML=OFF',
                          ]
                          )
-              self.spawn(['cmake', '--build', '.', '--target', 'install'] + build_args)
+              self.spawn(['cmake', '--build', '.', '-j', os.getenv('FREEBSD_MAKE_JOBS'), '--target', 'install'] + build_args)
               os.chdir(cwd)
             DEP_DIR = dep_inst_dir
 
@@ -297,7 +297,7 @@ class CMakeBuild(build_ext):
         os.chdir(build_temp)
         self.spawn(['cmake', SRC_DIR] + cmake_args)
         if not self.dry_run:
-            self.spawn(['cmake', '--build', '.', '--target', 'binding_python_lib'] + build_args)
+            self.spawn(['cmake', '--build', '.', '-j', os.getenv('FREEBSD_MAKE_JOBS'), '--target', 'binding_python_lib'] + build_args)
         
             # at this point the build should be complete, and we have all the files 
             # neeed in the temp build_folder
