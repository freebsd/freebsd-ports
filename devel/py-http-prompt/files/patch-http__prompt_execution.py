--- http_prompt/execution.py.orig	2016-05-20 07:19:56 UTC
+++ http_prompt/execution.py
@@ -241,7 +241,7 @@ class ExecutionVisitor(NodeVisitor):
             assert children[0].expr_name == 'action'
             output = BytesIO()
             try:
-                env = Environment(stdout=output)
+                env = Environment()
                 httpie_main(context.httpie_args(self.method), env=env)
                 content = output.getvalue()
             finally:
