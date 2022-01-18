--- setup.py.orig	2022-01-18 11:48:00 UTC
+++ setup.py
@@ -26,7 +26,7 @@ setup_kwargs = {
         ],
     "zip_safe": False,
     "scripts": ['amalgamate.py'],
-    "data_files": [("", ['LICENSE', 'README.rst']),],
+    "data_files": [("%%DOCSDIR%%", ['LICENSE', 'README.rst']),],
     }
 
 
