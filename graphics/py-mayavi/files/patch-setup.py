--- setup.py.orig	2016-08-01 19:02:36 UTC
+++ setup.py
@@ -403,12 +403,12 @@ def configuration(parent_package=None, t
     config.add_data_dir('mayavi/core/lut')
     config.add_data_dir('mayavi/tests/data')
     config.add_data_dir('mayavi/tests/csv_files')
-    config.add_data_dir('mayavi/tools/static')
+    config.add_data_dir('mayavi/tools/static/x3d')
 
     # Image files.
     for pkgdir in ('mayavi', 'tvtk'):
         for root, dirs, files in os.walk(pkgdir):
-            if split(root)[-1] == 'images':
+            if (split(root)[-1] == 'images') and files:
                 config.add_data_dir(root)
 
     # *.ini files.
