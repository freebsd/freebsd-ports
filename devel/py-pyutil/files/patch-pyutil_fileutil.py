Description: ReopenableNamedTemporaryFile.shutdown(), also run from
  __del__(), failed when the file was already gone, which lineify_file()
  does by moving it into place, so every 'lines' run printed an ignored
  FileNotFoundError. Ignore a missing file.
Issue ID: https://github.com/tpltnt/pyutil/pull/15
Changeset: none (upstream master has the same code)
TODO: Submit upstream; drop once a release includes the fix.

--- pyutil/fileutil.py.orig	2022-12-26 22:48:41 UTC
+++ pyutil/fileutil.py
@@ -174,7 +174,12 @@ class ReopenableNamedTemporaryFile:
         self.shutdown()
 
     def shutdown(self):
-        remove(self.name)
+        # The file may already be gone, e.g. moved into place by
+        # lineutil.lineify_file() or removed by an earlier shutdown().
+        try:
+            remove(self.name)
+        except FileNotFoundError:
+            pass
 
 def make_dirs(dirname, mode=0o777):
     """
