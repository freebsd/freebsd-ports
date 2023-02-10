--- setup.py.orig	2023-01-17 23:10:03 UTC
+++ setup.py
@@ -44,7 +44,7 @@ REQUIREMENTS = [
     'ipython<6; python_version<"3"',
     'ipython>=7.31.1,<9; python_version>="3"',
     'jupyter-client>=5.3.4,<6; python_version<"3"',
-    'jupyter-client>=7.4.9,<8; python_version>="3"',
+    'jupyter-client>=7.4.7; python_version>="3"',
     'pyzmq>=17,<20; python_version<"3"',
     'pyzmq>=22.1.0; python_version>="3"',
     'wurlitzer>=1.0.3;platform_system!="Windows"',
