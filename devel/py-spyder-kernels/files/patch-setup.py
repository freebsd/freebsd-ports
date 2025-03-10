--- setup.py.orig	2024-06-11 16:06:35 UTC
+++ setup.py
@@ -37,10 +37,10 @@ REQUIREMENTS = [
 
 REQUIREMENTS = [
     'cloudpickle',
-    'ipykernel>=6.29.3,<7',
+    'ipykernel>=6.29.3',
     'ipython>=8.12.2,<8.13; python_version=="3.8"',
-    'ipython>=8.13.0,<9,!=8.17.1; python_version>"3.8"',
-    'jupyter-client>=7.4.9,<9',
+    'ipython>=8.13.0,!=8.17.1; python_version>"3.8"',
+    'jupyter-client>=7.4.9',
     'pyzmq>=24.0.0',
     'wurlitzer>=1.0.3;platform_system!="Windows"',
     'pyxdg>=0.26;platform_system=="Linux"',
