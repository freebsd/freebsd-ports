--- setup.py.orig	2025-08-29 18:03:06 UTC
+++ setup.py
@@ -33,7 +33,7 @@ extras_require = {
 ]
 
 extras_require = {
-    'crt': ['awscrt==0.27.6'],
+    'crt': ['awscrt>=0.27.6'],
 }
 
 setup(
