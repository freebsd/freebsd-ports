--- setup.py.orig	2016-06-13 06:31:53.378976000 -0700
+++ setup.py	2016-06-13 06:32:11.276473000 -0700
@@ -46,6 +46,5 @@
     packages = ["Codeville", "Codeville/old"],
     ext_modules = plat_ext,
 
-    scripts = scripts,
-    data_files = data_files
+    scripts = scripts
     )
