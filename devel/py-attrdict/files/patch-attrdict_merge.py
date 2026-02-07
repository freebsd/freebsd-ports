--- attrdict/merge.py.orig	2019-02-01 22:18:30 UTC
+++ attrdict/merge.py
@@ -1,7 +1,7 @@
 """
 A right-favoring Mapping merge.
 """
-from collections import Mapping
+from collections.abc import Mapping
 
 
 __all__ = ['merge']
