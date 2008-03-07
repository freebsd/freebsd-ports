--- setup.py.orig	2007-07-03 07:11:15.000000000 +0900
+++ setup.py	2008-03-06 17:59:33.000000000 +0900
@@ -88,6 +88,8 @@
              "layer0","layer1","layer2",
              "layer3","layer4","layer5",
              "/usr/include/freetype2",
+             "%%LOCALBASE%%/include",
+             "%%LOCALBASE%%/include/freetype2",
 #             "/users/warren/ext/include",
 # VMD plugin support
 #             "contrib/uiuc/plugins/include",
@@ -98,6 +100,7 @@
    pyogl_libs = ["GL","GLU","glut"]
    lib_dirs=[
       "/usr/X11R6/lib",
+      "%%LOCALBASE%%/lib",
 #      "/users/warren/pymol/ext/lib"
       ]
    def_macros=[("_PYMOL_MODULE",None),
