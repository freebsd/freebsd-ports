--- ./setup.py.orig	2014-01-06 19:08:27.000000000 +0400
+++ ./setup.py	2014-01-07 15:36:44.000000000 +0400
@@ -41,7 +41,8 @@
 
 ext = Extension("hiredis.hiredis",
   sources=glob.glob("src/*.c"),
-  include_dirs=["vendor"])
+  include_dirs=["%%LOCALBASE%%/include"],
+  library_dirs=["%%LOCALBASE%%/lib"],)
 
 setup(
   name="hiredis",
@@ -53,7 +54,6 @@
   keywords=["Redis"],
   license="BSD",
   packages=["hiredis"],
-  libraries=[lib],
   ext_modules=[ext],
 
   # Override "install_lib" command
