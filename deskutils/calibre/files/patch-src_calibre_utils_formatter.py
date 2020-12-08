--- src/calibre/utils/formatter.py.orig	2020-11-13 01:58:49 UTC
+++ src/calibre/utils/formatter.py
@@ -536,7 +536,7 @@ class _Interpreter(object):
 
     def do_node_first_non_empty(self, prog):
         for expr in prog.expression_list:
-            if v := self.expr(expr):
+            if v == self.expr(expr):
                 return v
 
     NODE_OPS = {
