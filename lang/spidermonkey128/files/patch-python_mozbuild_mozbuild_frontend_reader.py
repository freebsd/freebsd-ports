--- python/mozbuild/mozbuild/frontend/reader.py.orig	2025-08-11 17:07:23 UTC
+++ python/mozbuild/mozbuild/frontend/reader.py
@@ -470,7 +470,7 @@ class TemplateFunction(object):
             return c(
                 ast.Subscript(
                     value=c(ast.Name(id=self._global_name, ctx=ast.Load())),
-                    slice=c(ast.Index(value=c(ast.Str(s=node.id)))),
+                    slice=c(ast.Index(value=c(ast.Constant(value=node.id)))),
                     ctx=node.ctx,
                 )
             )
@@ -1035,8 +1035,8 @@ class BuildReader(object):
                 else:
                     # Others
                     assert isinstance(target.slice, ast.Index)
-                    assert isinstance(target.slice.value, ast.Str)
-                    key = target.slice.value.s
+                    assert isinstance(target.slice.value, ast.Constant)
+                    key = target.slice.value.value
 
             return name, key
 
@@ -1044,11 +1044,11 @@ class BuildReader(object):
             value = node.value
             if isinstance(value, ast.List):
                 for v in value.elts:
-                    assert isinstance(v, ast.Str)
-                    yield v.s
+                    assert isinstance(v, ast.Constant)
+                    yield v.value
             else:
-                assert isinstance(value, ast.Str)
-                yield value.s
+                assert isinstance(value, ast.Constant)
+                yield value.value
 
         assignments = []
 
