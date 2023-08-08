--- python/mozbuild/mozbuild/util.py.orig	2021-09-28 10:04:57 UTC
+++ python/mozbuild/mozbuild/util.py
@@ -27,6 +27,11 @@ from collections import (
 )
 from io import (BytesIO, StringIO)
 
+if sys.version.startswith('2'):
+    from collections import Sequence
+else:
+    from collections.abc import Sequence
+
 import six
 
 if sys.platform == 'win32':
@@ -220,7 +225,7 @@ class FileAvoidWrite(BytesIO):
     still occur, as well as diff capture if requested.
     """
 
-    def __init__(self, filename, capture_diff=False, dry_run=False, readmode='rU'):
+    def __init__(self, filename, capture_diff=False, dry_run=False, readmode='r'):
         BytesIO.__init__(self)
         self.name = filename
         assert type(capture_diff) == bool
@@ -782,7 +787,7 @@ class HierarchicalStringList(object):
         self._strings = StrictOrderingOnAppendList()
         self._children = {}
 
-    class StringListAdaptor(collections.Sequence):
+    class StringListAdaptor(Sequence):
         def __init__(self, hsl):
             self._hsl = hsl
 
