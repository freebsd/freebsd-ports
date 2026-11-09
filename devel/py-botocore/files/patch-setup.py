--- setup.py.orig	2026-10-30 18:04:02 UTC
+++ setup.py
@@ -29,7 +29,7 @@ extras_require = {
 ]
 
 extras_require = {
-    'crt': ['awscrt==0.38.0'],
+    'crt': ['awscrt>=0.38.0'],
 }
 
 setup(
