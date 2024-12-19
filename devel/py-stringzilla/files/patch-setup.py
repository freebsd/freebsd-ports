--- setup.py.orig	2024-12-19 07:27:15 UTC
+++ setup.py
@@ -118,7 +118,7 @@ def windows_settings() -> Tuple[List[str], List[str], 
     return compile_args, link_args, macros_args
 
 
-if sys.platform == "linux":
+if sys.platform == "linux" or sys.platform.startswith('freebsd'):
     compile_args, link_args, macros_args = linux_settings()
 
 elif sys.platform == "darwin":
