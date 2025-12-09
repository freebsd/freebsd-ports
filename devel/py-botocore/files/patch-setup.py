--- setup.py.orig	2025-12-05 19:10:02 UTC
+++ setup.py
@@ -33,7 +33,7 @@ extras_require = {
 ]
 
 extras_require = {
-    'crt': ['awscrt==0.29.2'],
+    'crt': ['awscrt>=0.29.2'],
 }
 
 setup(
