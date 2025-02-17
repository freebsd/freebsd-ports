--- setup.py.orig	2025-01-30 20:10:23 UTC
+++ setup.py
@@ -33,7 +33,7 @@ extras_require = {
 ]
 
 extras_require = {
-    'crt': ['awscrt==0.23.8'],
+    'crt': ['awscrt>=0.23.8'],
 }
 
 setup(
