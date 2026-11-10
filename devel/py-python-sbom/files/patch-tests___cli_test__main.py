-- Locate the python-sbom console script on PATH so the test passes
-- before the port is installed, using the staged binary.
--- tests/_cli/test_main.py.orig	2026-11-10 10:07:23 UTC
+++ tests/_cli/test_main.py
@@ -1,6 +1,7 @@ import runpy
 from __future__ import annotations
 
 import runpy
+import shutil
 import subprocess
 import sys
 from pathlib import Path
@@ -26,7 +27,8 @@ def test_console_script() -> None:
 
 
 def test_console_script() -> None:
-    script = Path(sys.executable).parent / "python-sbom"
+    script = shutil.which("python-sbom")
+    assert script is not None
     assert subprocess.check_output([script, "--help"], text=True).startswith("usage: python-sbom ")
 
 
