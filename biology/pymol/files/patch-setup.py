--- setup.py	2012-02-14 04:02:02.000000000 +0900
+++ setup.py	2012-02-15 13:09:38.000000000 +0900
@@ -159,7 +159,8 @@
                  "layer3",
                  "layer4",
                  "layer5",
-                 "/usr/include/freetype2",
+                 "%%LOCALBASE%%/include/freetype2",
+                 "%%LOCALBASE%%/include",
               # VMD plugin support
               #              "contrib/uiuc/plugins/include",
               #              "contrib/uiuc/plugins/molfile_plugin/src",
@@ -181,7 +181,7 @@
                    "GLU",
                    "glut",
                    "GLEW"]
-    lib_dirs = [ "/usr/X11R6/lib64", ]
+    lib_dirs = [ "%%LOCALBASE%%/lib", ]
     def_macros = [ ("_PYMOL_MODULE",None),
                    ("_PYMOL_INLINE",None),
                    ("_PYMOL_FREETYPE",None),
@@ -201,7 +202,7 @@
                       "-funroll-loops",
                       "-O3",
                       "-g" ]
-    ext_link_args = []
+    ext_link_args = [ "-L%%LOCALBASE%%/lib" ]
 
 
 distribution = setup ( # Distribution meta-data

