--- testing/mozbase/manifestparser/manifestparser/filters.py.orig	2021-03-15 15:52:38 UTC
+++ testing/mozbase/manifestparser/manifestparser/filters.py
@@ -12,7 +12,13 @@ from __future__ import absolute_import
 
 import itertools
 import os
-from collections import defaultdict, MutableSequence
+import sys
+from collections import defaultdict
+
+if sys.version.startswith('2'):
+    from collections import MutableSequence
+else:
+    from collections.abc import MutableSequence
 
 import six
 from six import string_types
