--- pyqtbuild/bundle/bundle.py.orig	2021-10-12 12:00:18 UTC
+++ pyqtbuild/bundle/bundle.py
@@ -66,7 +66,7 @@ def bundle(wheel_path, qt_dir, build_tag_suffix, msvc_
             parts[-1] = parts[-1].replace('universal2', arch)
         else:
             raise UserException(
-                    "'{0}' is not supported by {1}".format(arch, wheel_name)
+                    "'{0}' is not supported by {1}".format(arch, wheel_name))
 
     # Get the package object.
     sub_parts = parts[0].split('_')
