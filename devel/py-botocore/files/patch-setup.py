--- setup.py.orig	2025-11-26 19:02:24 UTC
+++ setup.py
@@ -33,7 +33,7 @@ extras_require = {
 ]
 
 extras_require = {
-    'crt': ['awscrt==0.29.0'],
+    'crt': ['awscrt>=0.29.0'],
 }
 
 setup(
