--- setup.py.orig	2024-08-13 04:41:56 UTC
+++ setup.py
@@ -117,7 +117,7 @@ extras_require = {
     # TODO: move this to cpython_only_plugins when python 3.8 support is dropped
     "rawpy": [
         "rawpy",
-        "numpy>2",
+        "numpy",
     ],  # rawpy doesn't support python 3.8 (due to numpy > 2 requirement)
     "pillow-heif": ["pillow-heif"],  # pillow-heif doesn#t support py3.8 on MacOS ARM
 }
