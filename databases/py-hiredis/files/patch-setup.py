--- setup.py.orig	2015-04-03 14:08:45 UTC
+++ setup.py
@@ -45,7 +45,9 @@ lib = ("hiredis_for_hiredis_py", {
 
 ext = Extension("hiredis.hiredis",
   sources=glob.glob("src/*.c"),
-  include_dirs=["vendor"])
+  include_dirs=["%%LOCALBASE%%/include"],
+  library_dirs=["%%LOCALBASE%%/lib"],
+  libraries=["hiredis"],)
 
 setup(
   name="hiredis",
@@ -57,7 +59,6 @@ setup(
   keywords=["Redis"],
   license="BSD",
   packages=["hiredis"],
-  libraries=[lib],
   ext_modules=[ext],
 
   # Override "install_lib" command
