--- setup.py.orig	2014-06-20 11:45:12.000000000 -0700
+++ setup.py	2014-06-20 12:03:29.000000000 -0700
@@ -44,6 +44,5 @@
     packages = ["Codeville", "Codeville/old"],
     ext_modules = plat_ext,
 
-    scripts = scripts,
-    data_files = data_files
+    scripts = scripts
     )
