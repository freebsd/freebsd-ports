--- setup.py.orig	2023-08-29 01:06:59 UTC
+++ setup.py
@@ -21,7 +21,7 @@ if sys.argv[-1] == "publish":
 
 required = [
     "certifi",
-    "setuptools>=67.0.0",
+    "setuptools>=61.0.0",
     "virtualenv>=20.24.2",
 ]
 extras = {
