--- setup.py.orig	2020-01-19 16:34:33 UTC
+++ setup.py
@@ -34,7 +34,7 @@ setup(
     install_requires=[
         'future>=0.14.0; python_version<"3"',
         'futures; python_version<"3.2"',
-        'ujson<=1.35; platform_system!="Windows"',
+        'ujson; platform_system!="Windows"',
     ],
 
     # List additional groups of dependencies here (e.g. development
