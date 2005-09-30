
$FreeBSD$

--- setup.py.orig
+++ setup.py
@@ -1,7 +1,7 @@
 from distutils.core import setup, Extension
 
-GDCHART_PATH = "../gdchart0.11.4dev"
-GD_PATH = "../gd-1.8.4"
+GDCHART_PATH = "%%LOCALBASE%%/include"
+GD_PATH = "%%LOCALBASE%%/lib"
 setup(
             name="pygdchart",
             version="2.0 Beta",
