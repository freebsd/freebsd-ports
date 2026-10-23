Description: Fix view validation on Python 3.14: check ast.Constant values
  instead of ast.Str and .s.
Issue ID: none (not yet reported to https://github.com/odoo/odoo)
Changeset: none
TODO: Upstream not checked yet: check whether it is fixed there and submit it
  if not.

--- odoo/tools/view_validation.py.orig	2026-06-18 17:00:14 UTC
+++ odoo/tools/view_validation.py
@@ -86,9 +86,9 @@ def get_dict_asts(expr):
 
     if not isinstance(expr, ast.Dict):
         raise ValueError("Non-dict expression")
-    if not all(isinstance(key, ast.Str) for key in expr.keys):
+    if not all(isinstance(key, ast.Constant) and isinstance(key.value, str) for key in expr.keys):
         raise ValueError("Non-string literal dict key")
-    return {key.s: val for key, val in zip(expr.keys, expr.values)}
+    return {key.value: val for key, val in zip(expr.keys, expr.values)}
 
 
 def _check(condition, explanation):
@@ -112,10 +112,10 @@ def get_domain_identifiers(expr):
 
     if isinstance(expr, ast.List):
         for elem in expr.elts:
-            if isinstance(elem, ast.Str):
+            if isinstance(elem, ast.Constant) and isinstance(elem.value, str):
                 # note: this doesn't check the and/or structure
-                _check(elem.s in ('&', '|', '!'),
-                       f"logical operators should be '&', '|', or '!', found {elem.s!r}")
+                _check(elem.value in ('&', '|', '!'),
+                       f"logical operators should be '&', '|', or '!', found {elem.value!r}")
                 continue
 
             if not isinstance(elem, (ast.List, ast.Tuple)):
@@ -124,10 +124,10 @@ def get_domain_identifiers(expr):
             _check(len(elem.elts) == 3,
                    f"segments should have 3 elements, found {len(elem.elts)}")
             lhs, operator, rhs = elem.elts
-            _check(isinstance(operator, ast.Str),
+            _check(isinstance(operator, ast.Constant) and isinstance(operator.value, str),
                    f"operator should be a string, found {type(operator).__name__}")
-            if isinstance(lhs, ast.Str):
-                fnames.add(lhs.s)
+            if isinstance(lhs, ast.Constant) and isinstance(lhs.value, str):
+                fnames.add(lhs.value)
 
     vnames.update(get_variable_names(expr))

