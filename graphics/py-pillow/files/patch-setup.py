--- ./setup.py.orig	2012-05-28 18:52:42.000000000 +1000
+++ ./setup.py	2012-05-28 18:55:45.000000000 +1000
@@ -134,7 +134,12 @@
         if prefix:
             _add_directory(library_dirs, os.path.join(prefix, "lib"))
             _add_directory(include_dirs, os.path.join(prefix, "include"))
-
+            _add_directory(library_dirs,
+                os.path.join(os.getenv("PREFIX"), "lib"))
+            _add_directory(include_dirs,
+                os.path.join(os.getenv("PREFIX"), "include"))
+            _add_directory(include_dirs,
+                os.path.join(os.getenv("LOCALBASE"), "include"))
         #
         # locate tkinter libraries
 
