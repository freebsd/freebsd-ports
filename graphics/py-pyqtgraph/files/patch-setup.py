--- setup.py.orig	2021-04-19 21:31:31 UTC
+++ setup.py
@@ -143,7 +143,7 @@ setup(
                   "pyqtgraph": ["colors/maps/*.csv", "colors/maps/*.txt"],
                   },
     install_requires = [
-        'numpy>=1.17.0',
+        'numpy>0',
         ],
     **setupOpts
 )
