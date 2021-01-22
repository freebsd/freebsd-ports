--- tvtk/setup.py.orig	2016-08-01 19:02:36 UTC
+++ tvtk/setup.py
@@ -20,7 +20,7 @@ def configuration(parent_package=None, t
     config.add_subpackage('custom')
     config.add_subpackage('pipeline')
     config.add_data_dir('pipeline/images')
-    config.add_data_dir('pyface/images')
+#    config.add_data_dir('pyface/images')
     config.add_data_dir('tools/images')
 
     config.add_subpackage('plugins')
