--- python/mozbuild/mozbuild/backend/configenvironment.py.orig	2021-03-15 15:52:37 UTC
+++ python/mozbuild/mozbuild/backend/configenvironment.py
@@ -9,8 +9,13 @@ import six
 import sys
 import json
 
-from collections import Iterable, OrderedDict
+from collections import OrderedDict
 from types import ModuleType
+
+if sys.version.startswith('2'):
+    from collections import Iterable
+else:
+    from collections.abc import Iterable
 
 import mozpack.path as mozpath
 
