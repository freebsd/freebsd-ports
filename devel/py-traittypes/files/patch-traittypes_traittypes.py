-- Fix compatibility with newer versions of pandas and xarray
-- 
--- traittypes/traittypes.py.orig	2026-06-11 19:36:11 UTC
+++ traittypes/traittypes.py
@@ -141,7 +141,7 @@ class PandasType(SciType):
         if value is None or value is Undefined:
             return super(PandasType, self).validate(obj, value)
         try:
-            value = self.klass(value)
+            if not isinstance(value, self.klass): value = self.klass(value)
         except (ValueError, TypeError) as e:
             raise TraitError(e)
         return super(PandasType, self).validate(obj, value)
@@ -226,7 +226,7 @@ class XarrayType(SciType):
         if value is None or value is Undefined:
             return super(XarrayType, self).validate(obj, value)
         try:
-            value = self.klass(value)
+            if not isinstance(value, self.klass): value = self.klass(value)
         except (ValueError, TypeError) as e:
             raise TraitError(e)
         return super(XarrayType, self).validate(obj, value)
