--- breezy/bzr/index.py.orig	2021-12-07 02:24:26 UTC
+++ breezy/bzr/index.py
@@ -165,7 +165,7 @@ class GraphIndexBuilder(object):
         if self._key_length != len(key):
             raise BadIndexKey(key)
         for element in key:
-            if not element or type(element) != bytes or _whitespace_re.search(element) is not None:
+            if not element or not isinstance(element, bytes) or _whitespace_re.search(element) is not None:
                 raise BadIndexKey(key)
 
     def _external_references(self):
