--- setup.py.orig	2024-04-17 18:23:08 UTC
+++ setup.py
@@ -33,7 +33,7 @@ extras_require = {
 ]
 
 extras_require = {
-    'crt': ['awscrt==0.20.9'],
+    'crt': ['awscrt>=0.20.9'],
 }
 
 setup(
