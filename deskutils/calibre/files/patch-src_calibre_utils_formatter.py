--- src/calibre/utils/formatter.py.orig	2021-04-16 02:20:00 UTC
+++ src/calibre/utils/formatter.py
@@ -888,7 +888,8 @@ class _Interpreter(object):
 
     def do_node_first_non_empty(self, prog):
         for expr in prog.expression_list:
-            if v := self.expr(expr):
+            v = self.expr(expr)
+            if v:
                 if (self.break_reporter):
                     self.break_reporter(prog.node_name, v, prog.line_number)
                 return v
