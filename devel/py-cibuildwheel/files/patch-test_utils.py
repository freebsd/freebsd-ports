--- test/utils.py.orig	2025-03-31 08:27:36 UTC
+++ test/utils.py
@@ -30,6 +30,8 @@ elif sys.platform.startswith("linux"):
     pass
 elif sys.platform.startswith("linux"):
     platform = "linux"
+elif sys.platform.startswith("freebsd"):
+    platform = "freebsd"
 elif sys.platform.startswith("darwin"):
     platform = "macos"
 elif sys.platform.startswith(("win32", "cygwin")):
@@ -67,7 +69,7 @@ def _update_pip_cache_dir(env: dict[str, str]) -> None
 def _update_pip_cache_dir(env: dict[str, str]) -> None:
     # Fix for pip concurrency bug https://github.com/pypa/pip/issues/11340
     # See https://github.com/pypa/cibuildwheel/issues/1254 for discussion.
-    if platform == "linux":
+    if platform == "linux" or platform == "freebsd":
         return
     if "PIP_CACHE_DIR" in env:
         return
