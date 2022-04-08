--- setup.py.orig	2022-04-04 18:26:03 UTC
+++ setup.py
@@ -30,7 +30,7 @@ with open_relative("README.rst") as f:
 
 requires = [
     'oci==2.62.1',
-    'arrow>=1.0.0',
+    'arrow>>=1.0.0',
     'certifi',
     'click==7.1.2',
     'cryptography>=3.2.1,<=3.4.7',
