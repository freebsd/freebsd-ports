- prevent versioning via git

--- setup.py.orig	2022-05-31 02:31:10 UTC
+++ setup.py
@@ -3,6 +3,6 @@ from setuptools import find_packages, setup
 
 setup(
     packages=find_packages(),
-    pbr=True,
-    setup_requires=['pbr'],
+    #pbr=True,
+    #setup_requires=['pbr'],
 )
