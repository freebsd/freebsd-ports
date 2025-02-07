--- setup.py.orig	2025-01-28 19:02:34 UTC
+++ setup.py
@@ -33,7 +33,7 @@ extras_require = {
 ]
 
 extras_require = {
-    'crt': ['awscrt==0.23.4'],
+    'crt': ['awscrt>=0.23.4'],
 }
 
 setup(
