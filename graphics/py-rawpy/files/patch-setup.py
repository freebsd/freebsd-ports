--- setup.py.orig	2024-06-22 08:25:57 UTC
+++ setup.py
@@ -308,5 +308,5 @@ setup(
       packages = find_packages(),
       ext_modules = extensions,
       package_data = package_data,
-      install_requires=['numpy >= 2.0']
+      install_requires=['numpy']
 )
