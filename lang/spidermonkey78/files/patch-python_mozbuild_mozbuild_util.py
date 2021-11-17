--- python/mozbuild/mozbuild/util.py.orig	2021-03-15 15:52:38 UTC
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
@@ -782,7 +787,7 @@ class HierarchicalStringList(object):
         self._strings = StrictOrderingOnAppendList()
         self._children = {}
 
-    class StringListAdaptor(collections.Sequence):
+    class StringListAdaptor(Sequence):
         def __init__(self, hsl):
             self._hsl = hsl
 
