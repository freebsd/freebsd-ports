--- python/mozbuild/mozbuild/frontend/reader.py.orig	2026-07-15 20:30:36 UTC
+++ python/mozbuild/mozbuild/frontend/reader.py
@@ -470,7 +470,7 @@ class TemplateFunction:
             return c(
                 ast.Subscript(
                     value=c(ast.Name(id=self._global_name, ctx=ast.Load())),
-                    slice=c(ast.Index(value=c(ast.Str(s=node.id)))),
+                    slice=c(ast.Index(value=c(ast.Constant(value=node.id)))),
                     ctx=node.ctx,
                 )
             )
@@ -1039,8 +1039,8 @@ class BuildReader:
                 else:
                     # Others
                     assert isinstance(target.slice, ast.Index)
-                    assert isinstance(target.slice.value, ast.Str)
-                    key = target.slice.value.s
+                    assert isinstance(target.slice.value, ast.Constant)
+                    key = target.slice.value.value
             elif isinstance(target, ast.Attribute):
                 assert isinstance(target.attr, str)
                 key = target.attr
@@ -1051,11 +1051,11 @@ class BuildReader:
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
 
