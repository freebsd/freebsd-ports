-- Fix tests for FreeBSD (don't delete temporary files on close, fix np.int).

--- tests/test_validator.py.orig	2026-06-08 10:21:32 UTC
+++ tests/test_validator.py
@@ -9,7 +9,7 @@ class LoomValidatorTests(TestCase):
 
 class LoomValidatorTests(TestCase):
     def test_file_with_empty_col_attrs_is_valid(self) -> None:
-        f = NamedTemporaryFile(suffix=".loom")
+        f = NamedTemporaryFile(suffix=".loom", delete=False)
         f.close()
         loompy.create(f.name, np.zeros((5, 5)), {}, {})
         try:
