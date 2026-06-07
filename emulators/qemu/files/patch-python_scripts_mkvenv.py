--- python/scripts/mkvenv.py.orig	2026-06-07 15:16:26 UTC
+++ python/scripts/mkvenv.py
@@ -799,8 +799,7 @@ def _do_ensure(
         env = dict(os.environ)
         env['PIP_CONFIG_SETTINGS'] = "editable_mode=compat"
         pip_install(
-            args=["--no-build-isolation",
-                  "-e"] + local_packages,
+            args=["--no-build-isolation"] + local_packages,
             online=online,
             wheels_dir=wheels_dir,
             env=env,
