--- setup.py.orig	2026-10-03 13:50:47 UTC
+++ setup.py
@@ -7,7 +7,7 @@ setup(
     long_description = f.read()
 
 setup(
-    name                          = "Tapi",
+    name                          = "tapi",
     version                       = "0.2.3",
     description                   = "Tines REST API wrapper",
     long_description              = long_description,
@@ -25,4 +25,4 @@ setup(
         "dev": ["pytest", "twine"],
     },
     python_requires               = ">=3.10"
-)
\ No newline at end of file
+)
