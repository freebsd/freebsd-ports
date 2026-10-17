Description: Fix Python 2 leftovers: estimate_mem_of_obj() uses unicode and
  long; describe_object*() read func_name/im_func and use iteritems()/next();
  dump_description_of_object_refs() uses __dict__.iteritems() behind a bare
  except; describe_all_objects() does an implicit relative 'import dictutil';
  Measurer passes a one-shot zip() to linear_fit_slope(); the stats helpers
  use the reduce builtin.
Issue ID: https://github.com/tpltnt/pyutil/pull/15
Changeset: none (upstream master has the same code)
TODO: Submit upstream; drop once a release includes the fix.

--- pyutil/memutil.py.orig	2022-12-26 22:48:41 UTC
+++ pyutil/memutil.py
@@ -7,6 +7,7 @@ from __future__ import print_function
 
 # from the Python Standard Library
 import gc, math, operator, os, sys, types
+from functools import reduce
 try:
     StandardError # PY2
 except NameError:
@@ -31,9 +32,9 @@ def estimate_mem_of_obj(o):
     # assumes 32-bit CPUs...
     PY_STRUCT_HEAD_LEN=4
     if hasattr(o, '__len__'):
-        if isinstance(o, str):
+        if isinstance(o, bytes):
             return PY_STRUCT_HEAD_LEN + o.__len__() * 1
-        if isinstance(o, unicode):
+        if isinstance(o, str):
             return PY_STRUCT_HEAD_LEN + o.__len__() * 4 # 4 depends on implementation and is approximate
         if isinstance(o, (tuple, list,)):
             return PY_STRUCT_HEAD_LEN + o.__len__() * 4
@@ -41,12 +42,6 @@ def estimate_mem_of_obj(o):
             return PY_STRUCT_HEAD_LEN + o.__len__() * 4 * 2 * 2 # approximate
     if isinstance(o, int):
         return PY_STRUCT_HEAD_LEN + 4
-    if isinstance(o, long):
-        return PY_STRUCT_HEAD_LEN + 4
-        if o < 1:
-            return PY_STRUCT_HEAD_LEN
-        else:
-            return PY_STRUCT_HEAD_LEN + math.log(o) / 5 # the 5 was empirically determined (it is approximate)
     if isinstance(o, float):
         return PY_STRUCT_HEAD_LEN + 8
 
@@ -311,7 +306,7 @@ class Measurer(object):
             self._invoke()
             return
 
-        self.d.callback(mathutil.linear_fit_slope(zip(self.resiters, self.resmemusage)))
+        self.d.callback(mathutil.linear_fit_slope(list(zip(self.resiters, self.resmemusage))))
 
 def measure_mem_leakage(f, numsamples=2**7, iterspersample=2**4, *args, **kwargs):
     """
@@ -365,12 +360,12 @@ def describe_object(o, FunctionType=type
     sl = []
     if isinstance(o, FunctionType):
         try:
-            sl.append("<type 'function' %s>" % str(o.func_name))
+            sl.append("<type 'function' %s>" % str(o.__name__))
         except:
             pass
     elif isinstance(o, MethodType):
         try:
-            sl.append("<type 'method' %s>" % str(o.im_func.func_name))
+            sl.append("<type 'method' %s>" % str(o.__func__.__name__))
         except:
             pass
     else:
@@ -387,12 +382,12 @@ def describe_object_with_dict_details(o)
     sl.append(str(type(o)))
     if isinstance(o, types.FunctionType):
         try:
-            sl.append(str(o.func_name))
+            sl.append(str(o.__name__))
         except:
             pass
     elif isinstance(o, types.MethodType):
         try:
-            sl.append(str(o.im_func.func_name))
+            sl.append(str(o.__func__.__name__))
         except:
             pass
     try:
@@ -402,12 +397,12 @@ def describe_object_with_dict_details(o)
     if isinstance(o, dict) and o:
         sl.append('-')
         nd = dictutil.NumDict()
-        for k, v in o.iteritems():
+        for k, v in o.items():
             nd.inc((describe_object(k), describe_object(v),))
         k, v = nd.item_with_largest_value()
         sl.append("-")
-        iterator = o.iteritems()
-        k,v =  iterator.next()
+        iterator = iter(o.items())
+        k,v =  next(iterator)
         sl.append(describe_object(k))
         sl.append(":")
         sl.append(describe_object(v))
@@ -419,7 +414,7 @@ def describe_dict(o):
     sl.append(str(l))
     if l:
         sl.append("-")
-        iterator = o.iteritems()
+        iterator = iter(o.items())
         firstitem=True
         try:
             while True:
@@ -427,7 +422,7 @@ def describe_dict(o):
                     firstitem = False
                 else:
                     sl.append(", ")
-                k,v =  iterator.next()
+                k,v =  next(iterator)
                 sl.append(describe_object(k))
                 sl.append(": ")
                 sl.append(describe_object(v))
@@ -480,7 +475,6 @@ def get_all_objects():
     return objs
 
 def describe_all_objects():
-    import dictutil
     d = dictutil.NumDict()
     for o in get_all_objects():
         d.inc(describe_object(o))
@@ -498,7 +492,7 @@ def dump_description_of_object_refs(o, f
 
     # First, any __dict__ items
     try:
-        itemsiter = o.__dict__.iteritems()
+        itemsiter = o.__dict__.items()
     except:
         pass
     else:
