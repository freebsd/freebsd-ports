--- setup.py.orig	2024-03-28 16:48:27 UTC
+++ setup.py
@@ -21,7 +21,6 @@ setup_requires = [
     install_reqs += f.read().splitlines()
 
 setup_requires = [
-    'pytest-runner == 5.3.2',
 ]
 
 # WARNING: This imposes limitations on test/requirements.txt such that the
