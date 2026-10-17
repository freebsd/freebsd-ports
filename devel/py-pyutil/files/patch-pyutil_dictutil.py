Description: Fix Python 2 leftovers: move()/subtract() use dict.has_key()
  (and subtract() deletes while iterating a keys view), and NumDict uses
  it.next(), list.sort() on dict.items() and the reduce builtin.
Issue ID: to be filed upstream
Changeset: none (upstream master has the same code)
TODO: Submit upstream; drop once a release includes the fix.

--- pyutil/dictutil.py.orig	2022-12-26 22:48:42 UTC
+++ pyutil/dictutil.py
@@ -6,6 +6,7 @@ Tools to mess with dicts.
 import warnings
 
 import copy, operator
+from functools import reduce
 from bisect import bisect_left, insort_left
 
 from pyutil.assertutil import _assert, precondition
@@ -15,7 +16,7 @@ def move(k, d1, d2, strict=False):
     Move item with key k from d1 to d2.
     """
     warnings.warn("deprecated", DeprecationWarning)
-    if strict and not d1.has_key(k):
+    if strict and k not in d1:
         raise KeyError(k)
 
     d2[k] = d1[k]
@@ -30,11 +31,11 @@ def subtract(d1, d2):
     warnings.warn("deprecated", DeprecationWarning)
     if len(d1) > len(d2):
         for k in d2.keys():
-            if d1.has_key(k):
+            if k in d1:
                 del d1[k]
     else:
-        for k in d1.keys():
-            if d2.has_key(k):
+        for k in list(d1.keys()):
+            if k in d2:
                 del d1[k]
     return d1
 
@@ -76,7 +77,7 @@ class UtilDict:
         """
         @return a sequence of (key, value,) pairs sorted according to key
         """
-        l = self.d.items()
+        l = list(self.d.items())
         l.sort()
         return l
 
@@ -237,7 +238,7 @@ class NumDict:
         (winner, winnerval,) = next(it)
         try:
             while True:
-                n, nv = it.next()
+                n, nv = next(it)
                 if nv > winnerval:
                     winner = n
                     winnerval = nv
@@ -249,7 +250,7 @@ class NumDict:
         """
         @return a sequence of (key, value,) pairs sorted according to key
         """
-        l = self.d.items()
+        l = list(self.d.items())
         l.sort()
         return l
 
