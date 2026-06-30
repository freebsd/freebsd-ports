--- breezy/lockdir.py.orig	2021-12-07 02:24:26 UTC
+++ breezy/lockdir.py
@@ -803,7 +803,7 @@ class LockHeldInfo(object):
 
     def __eq__(self, other):
         """Equality check for lock holders."""
-        if type(self) != type(other):
+        if not isinstance(self, type(other)):
             return False
         return self.info_dict == other.info_dict
 
