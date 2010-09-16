--- setup.py.bak	2010-09-16 10:45:18.000000000 +0900
+++ setup.py	2010-09-16 10:51:57.000000000 +0900
@@ -127,7 +127,8 @@
     inc_dirs=["ov/src",
               "layer0","layer1","layer2",
               "layer3","layer4","layer5",
-              "/usr/include/freetype2",
+              "%%LOCALBASE%%/include",
+              "%%LOCALBASE%%/include/freetype2",
 #                 "/users/warren/ext/include",
 # VMD plugin support
 #              "contrib/uiuc/plugins/include",
@@ -139,7 +140,7 @@
           ]	
     pyogl_libs = ["GL","GLU","glut"]
     lib_dirs=[
-        "/usr/X11R6/lib",
+         "%%LOCALBASE%%/lib",
 #        "/users/warren/pymol/ext/lib"
         ]
     def_macros=[("_PYMOL_MODULE",None),
