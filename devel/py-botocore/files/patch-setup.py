--- setup.py.orig	2026-04-29 19:50:04 UTC
+++ setup.py
@@ -29,7 +29,7 @@ extras_require = {
 ]
 
 extras_require = {
-    'crt': ['awscrt==0.36.0'],
+    'crt': ['awscrt>=0.36.0'],
 }
 
 setup(
