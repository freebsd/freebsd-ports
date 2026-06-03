Fix command name for non-default Python versions

If py-maturin is built for a non-default flavor (e.g., 'make FLAVOR=py313'),
the port installs "bin/maturin-3.13" and does not install "bin/maturin" which
is normal and expected.

The "site-packages/maturin/__init__.py" file, however, explicitly defines the
command to use as 'maturin'.

--- maturin/__init__.py.orig	2006-07-24 01:21:28 UTC
+++ maturin/__init__.py
@@ -95,7 +95,7 @@ def _build_wheel(
 ) -> str:
     # PEP 517 specifies that only `sys.executable` points to the correct
     # python interpreter
-    base_command = ["maturin", "pep517", "build-wheel"]
+    base_command = ["maturin-%%PYTHON_VER%%", "pep517", "build-wheel"]
     options = _additional_pep517_args()
     if editable:
         options.append("--editable")
