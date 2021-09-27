--- src/debugpy/_vendored/pydevd/_pydevd_bundle/pydevd_exec.py.orig	2021-09-26 20:08:05 UTC
+++ src/debugpy/_vendored/pydevd/_pydevd_bundle/pydevd_exec.py
@@ -1,5 +1,5 @@
 def Exec(exp, global_vars, local_vars=None):
     if local_vars is not None:
-        exec exp in global_vars, local_vars
+        exec(exp, global_vars, local_vars)
     else:
-        exec exp in global_vars
\ No newline at end of file
+        exec(exp, global_vars)
