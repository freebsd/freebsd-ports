--- pylib/gyp/common.py.orig	2020-05-12 14:59:53 UTC
+++ pylib/gyp/common.py
@@ -12,6 +12,11 @@ import sys
 import tempfile
 import sys
 
+if sys.version_info.major == 3 and sys.version_info.minor >= 10:
+    from collections.abc import MutableSet
+    collections.MutableSet = collections.abc.MutableSet
+else:
+    from collections import MutableSet
 
 # A minimal memoizing decorator. It'll blow up if the args aren't immutable,
 # among other "problems".
@@ -494,7 +499,7 @@ def uniquer(seq, idfun=None):
 
 
 # Based on http://code.activestate.com/recipes/576694/.
-class OrderedSet(collections.MutableSet):
+class OrderedSet(MutableSet):
   def __init__(self, iterable=None):
     self.end = end = []
     end += [None, end, end]         # sentinel node for doubly linked list
