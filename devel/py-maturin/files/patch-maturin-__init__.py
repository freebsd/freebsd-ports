--- maturin/__init__.py.orig	2024-03-21 12:30:28 UTC
+++ maturin/__init__.py
@@ -64,7 +64,7 @@ def _build_wheel(
     # PEP 517 specifies that only `sys.executable` points to the correct
     # python interpreter
     base_command = [
-        "maturin",
+        "maturin-%%PYTHON_VER%%",
         "pep517",
         "build-wheel",
         "-i",
