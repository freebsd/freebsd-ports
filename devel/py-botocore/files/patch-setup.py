--- setup.py.orig	2024-06-06 18:05:57 UTC
+++ setup.py
@@ -33,7 +33,7 @@ extras_require = {
 ]
 
 extras_require = {
-    'crt': ['awscrt==0.20.11'],
+    'crt': ['awscrt>=0.20.11'],
 }
 
 setup(
