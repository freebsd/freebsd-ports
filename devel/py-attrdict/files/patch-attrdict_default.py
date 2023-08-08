--- attrdict/default.py.orig	2019-02-01 22:18:30 UTC
+++ attrdict/default.py
@@ -1,7 +1,7 @@
 """
 A subclass of MutableAttr that has defaultdict support.
 """
-from collections import Mapping
+from collections.abc import Mapping
 
 import six
 
