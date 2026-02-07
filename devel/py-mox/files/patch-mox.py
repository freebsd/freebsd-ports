--- mox.py.orig	2010-07-10 18:26:30 UTC
+++ mox.py
@@ -1229,7 +1229,7 @@ class Comparator:
       rhs: any python object
     """
 
-    raise NotImplementedError, 'method must be implemented by a subclass.'
+    raise NotImplementedError('method must be implemented by a subclass.')
 
   def __eq__(self, rhs):
     return self.equals(rhs)
