--- setup.py.orig	2024-02-28 01:51:49 UTC
+++ setup.py
@@ -41,13 +41,13 @@ REQUIREMENTS = [
     'cloudpickle',
     'ipykernel>=4.5,<5; python_version<"3"',
     'ipykernel>=6.16.1,<6.17; python_version<"3.8"',
-    'ipykernel>=6.29.3,<7; python_version>="3.8"',
+    'ipykernel>=6.29.3; python_version>="3.8"',
     'ipython<6; python_version<"3"',
     'ipython>=7.31.1,<8; python_version<"3.8"',
     'ipython>=8.12.2,<8.13; python_version=="3.8"',
-    'ipython>=8.13.0,<9,!=8.17.1; python_version>"3.8"',
+    'ipython>=8.13.0,!=8.17.1; python_version>"3.8"',
     'jupyter-client>=5.3.4,<6; python_version<"3"',
-    'jupyter-client>=7.4.9,<9; python_version>="3"',
+    'jupyter-client>=7.4.9; python_version>="3"',
     'pyzmq>=17,<20; python_version<"3"',
     'pyzmq>=24.0.0; python_version>="3"',
     'wurlitzer>=1.0.3;platform_system!="Windows"',
