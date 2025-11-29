--- setup.py.orig	2025-11-18 19:01:56 UTC
+++ setup.py
@@ -33,7 +33,7 @@ extras_require = {
 ]
 
 extras_require = {
-    'crt': ['awscrt==0.28.4'],
+    'crt': ['awscrt>=0.28.4'],
 }
 
 setup(
