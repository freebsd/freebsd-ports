--- attrdict/mapping.py.orig	2022-12-06 06:58:43 UTC
+++ attrdict/mapping.py
@@ -1,7 +1,7 @@
 """
 An implementation of MutableAttr.
 """
-from collections import Mapping
+from collections.abc import Mapping
 
 import six
 
