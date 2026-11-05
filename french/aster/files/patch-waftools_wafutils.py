--- waftools/wafutils.py.orig	2026-09-11 16:05:37 UTC
+++ waftools/wafutils.py
@@ -21,6 +21,11 @@ def exec_pyaster(self, pyfile, args, **kwargs):
     python = list(env.PYTHON)[0]
 
     python_ld_path = env.ASTERLIBDIR
+    # Fix destdir
+    from waflib import Options
+    destdir = getattr(Options.options, "destdir", None)
+    if destdir:
+        python_ld_path = destdir + python_ld_path
     add_to_env_paths(self, environ, "PYTHONPATH", python_ld_path)
     add_to_env_paths(self, environ, "LD_LIBRARY_PATH", python_ld_path)
 
