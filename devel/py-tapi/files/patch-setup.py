--- setup.py.orig	2026-04-04 18:22:55 UTC
+++ setup.py
@@ -7,7 +7,7 @@ setup(
     long_description = f.read()
 
 setup(
-    name                          = "Tapi",
+    name                          = "tapi",
     version                       = "0.2.2",
     description                   = "Tines REST API wrapper",
     long_description              = long_description,
@@ -25,4 +25,4 @@ setup(
         "dev": ["pytest", "twine"],
     },
     python_requires               = ">=3.10"
-)
\ No newline at end of file
+)
