- The first patch is to fix build by accepting tvtk_classes.zip,
- otherwise the build SEGVs on some platforms.
- Rebuilding tvtk_classes.zip seems to cause SEGVs.

- Misc other patches.

--- setup.py.orig	2022-10-17 14:42:18 UTC
+++ setup.py
@@ -260,7 +260,7 @@ def _tvtk_built_recently(zipfile, delay):
 def build_tvtk_classes_zip():
     MY_DIR = os.path.dirname(__file__)
     zipfile = os.path.join(MY_DIR, 'tvtk', 'tvtk_classes.zip')
-    if _tvtk_built_recently(zipfile, delay=120):
+    if True or _tvtk_built_recently(zipfile, delay=120):
         print("Already built tvtk_classes.zip")
         return
     else:
@@ -378,12 +378,12 @@ def configuration(parent_package=None, top_path=None):
     config.add_data_dir('mayavi/core/lut')
     config.add_data_dir('mayavi/tests/data')
     config.add_data_dir('mayavi/tests/csv_files')
-    config.add_data_dir('mayavi/tools/static')
+    config.add_data_dir('mayavi/tools/static/x3d')
 
     # Image files.
     for pkgdir in ('mayavi', 'tvtk'):
         for root, dirs, files in os.walk(pkgdir):
-            if split(root)[-1] == 'images':
+            if split(root)[-1] == 'images' and files:
                 config.add_data_dir(root)
 
     # *.ini files.
