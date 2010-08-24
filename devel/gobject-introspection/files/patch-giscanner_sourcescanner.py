--- giscanner/sourcescanner.py.orig
+++ giscanner/sourcescanner.py
@@ -196,7 +196,7 @@ class SourceSymbol(object):
 class SourceScanner(object):
 
     def __init__(self):
-        with LibtoolImporter:
+        with LibtoolImporter(None, None):
             from giscanner._giscanner import SourceScanner
         self._scanner = SourceScanner()
         self._filenames = []
