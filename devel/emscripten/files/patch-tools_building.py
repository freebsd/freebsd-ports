-- disable binaryen version checking

--- tools/building.py.orig	2026-04-22 03:51:59 UTC
+++ tools/building.py
@@ -1239,7 +1239,7 @@ def check_binaryen(bindir):
 
   # Allow the expected version or the following one in order avoid needing to update both
   # emscripten and binaryen in lock step in emscripten-releases.
-  if version not in {EXPECTED_BINARYEN_VERSION, EXPECTED_BINARYEN_VERSION + 1}:
+  if False and version not in {EXPECTED_BINARYEN_VERSION, EXPECTED_BINARYEN_VERSION + 1}:
     diagnostics.warning('version-check', 'unexpected binaryen version: %s (expected %s)', version, EXPECTED_BINARYEN_VERSION)
 
 
