--- BTrees/convert.py.orig	Fri Dec  3 01:25:34 2004
+++ BTrees/convert.py	Fri Dec  3 01:26:15 2004
@@ -13,11 +13,11 @@
 ##############################################################################
 
 
-def convert(old, new, threshold=200, f=None, None=None):
+def convert(old, new, threshold=200, f=None, _None=None):
     "Utility for converting old btree to new"
     n=0
     for k, v in old.items():
-        if f is not None: v=f(v)
+        if f is not _None: v=f(v)
         new[k]=v
         n=n+1
         if n > threshold:
