--- setup.py.orig	2024-09-10 18:18:37 UTC
+++ setup.py
@@ -33,7 +33,7 @@ extras_require = {
 ]
 
 extras_require = {
-    'crt': ['awscrt==0.21.5'],
+    'crt': ['awscrt>=0.21.5'],
 }
 
 setup(
