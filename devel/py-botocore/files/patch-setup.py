--- setup.py.orig	2026-02-16 19:11:44 UTC
+++ setup.py
@@ -33,7 +33,7 @@ extras_require = {
 ]
 
 extras_require = {
-    'crt': ['awscrt==0.31.2'],
+    'crt': ['awscrt>=0.31.2'],
 }
 
 setup(
