--- setup.py.orig	2024-10-10 18:04:14 UTC
+++ setup.py
@@ -33,7 +33,7 @@ extras_require = {
 ]
 
 extras_require = {
-    'crt': ['awscrt==0.22.0'],
+    'crt': ['awscrt>=0.22.0'],
 }
 
 setup(
