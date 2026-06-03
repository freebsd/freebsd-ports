--- setup.py.orig	2026-04-29 19:50:04 UTC
+++ setup.py
@@ -29,7 +29,7 @@ extras_require = {
 ]
 
 extras_require = {
-    'crt': ['awscrt==0.32.2'],
+    'crt': ['awscrt>=0.32.2'],
 }
 
 setup(
