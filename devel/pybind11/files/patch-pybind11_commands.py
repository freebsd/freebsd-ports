--- pybind11/commands.py.orig	2026-04-14 05:00:01 UTC
+++ pybind11/commands.py
@@ -31,7 +31,7 @@ def get_pkgconfig_dir() -> str:
     """
     Return the path to the pybind11 pkgconfig directory.
     """
-    pkgconfig_installed_path = os.path.join(DIR, "share", "pkgconfig")
+    pkgconfig_installed_path = os.path.join(DIR, "libdata", "pkgconfig")
     if os.path.exists(pkgconfig_installed_path):
         return pkgconfig_installed_path
 
