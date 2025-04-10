--- setuptools/_vendor/importlib_metadata/__init__.py.orig	2022-07-04 02:25:25 UTC
+++ setuptools/_vendor/importlib_metadata/__init__.py
@@ -14,7 +14,7 @@ import collections
 import posixpath
 import collections
 
-from . import _adapters, _meta
+from . import _adapters, _meta, _py39compat
 from ._collections import FreezableDefaultDict, Pair
 from ._compat import (
     NullFinder,
@@ -180,6 +180,10 @@ class EntryPoint(DeprecatedTuple):
     following the attr, and following any extras.
     """
 
+    name: str
+    value: str
+    group: str
+
     dist: Optional['Distribution'] = None
 
     def __init__(self, name, value, group):
@@ -350,7 +354,8 @@ class EntryPoints(DeprecatedList):
         Select entry points from self that match the
         given parameters (typically group and/or name).
         """
-        return EntryPoints(ep for ep in self if ep.matches(**params))
+        candidates = (_py39compat.ep_matches(ep, **params) for ep in self)
+        return EntryPoints(ep for ep, predicate in candidates if predicate)
 
     @property
     def names(self):
@@ -991,7 +996,7 @@ def entry_points(**params) -> Union[EntryPoints, Selec
 
     :return: EntryPoints or SelectableGroups for all installed packages.
     """
-    norm_name = operator.attrgetter('_normalized_name')
+    norm_name = _py39compat.normalized_name
     unique = functools.partial(unique_everseen, key=norm_name)
     eps = itertools.chain.from_iterable(
         dist.entry_points for dist in unique(distributions())
