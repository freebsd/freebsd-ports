--- setup.py.orig	2024-10-14 02:48:52 UTC
+++ setup.py
@@ -104,7 +104,7 @@ cpython_only_plugins = {
 
 cpython_only_plugins = {
     "fits": ["astropy"],
-    "rawpy": ["rawpy", "numpy>2"],
+    "rawpy": ["rawpy", "numpy"],
 }
 
 extras_require = {
