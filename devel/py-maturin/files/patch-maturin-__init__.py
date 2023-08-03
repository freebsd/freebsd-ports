--- maturin/__init__.py.orig	2022-08-14 11:03:56 UTC
+++ maturin/__init__.py
@@ -52,7 +52,7 @@ def _build_wheel(
     # PEP 517 specifies that only `sys.executable` points to the correct
     # python interpreter
     command = [
-        "maturin",
+        "maturin-%%PYTHON_VER%%",
         "pep517",
         "build-wheel",
         "-i",
