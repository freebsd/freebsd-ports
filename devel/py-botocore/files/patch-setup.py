--- setup.py.orig	2024-08-06 18:07:09 UTC
+++ setup.py
@@ -33,7 +33,7 @@ extras_require = {
 ]
 
 extras_require = {
-    'crt': ['awscrt==0.21.2'],
+    'crt': ['awscrt>=0.21.2'],
 }
 
 setup(
