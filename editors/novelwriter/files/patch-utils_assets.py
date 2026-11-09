--- utils/assets.py.orig	2026-11-09 11:30:04 UTC
+++ utils/assets.py
@@ -377,7 +377,7 @@ def getLReleaseExec() -> str | None:
 
 def getLReleaseExec() -> str | None:
     """Look for the lrelease executable."""
-    for entry in ["lrelease-qt6", "lrelease"]:
+    for entry in ["lrelease-qt6", "lrelease6"]:
         if subprocess.call(f"type {entry}", shell=True) == 0:
             return entry
     return None
