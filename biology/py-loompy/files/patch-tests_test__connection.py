-- Fix tests for FreeBSD (don't delete temporary files on close, fix np.int).

-- Fix np.int usage for NumPy 2.0+ compatibility.

--- tests/test_connection.py.orig	2021-10-05 14:19:26 UTC
+++ tests/test_connection.py
@@ -8,16 +8,16 @@ class LoomConnectionTests(TestCase):
 
 class LoomConnectionTests(TestCase):
     def setUp(self) -> None:
-        self.file = NamedTemporaryFile(suffix=".loom")
+        self.file = NamedTemporaryFile(suffix=".loom", delete=False)
         self.file.close()
         loompy.create(
             self.file.name,
             np.random.random((5, 5)),
             row_attrs={
-                "key": np.fromiter(range(5), dtype=np.int)
+                "key": np.fromiter(range(5), dtype=int)
             },
             col_attrs={
-                "key": np.fromiter(range(5), dtype=np.int)
+                "key": np.fromiter(range(5), dtype=int)
             })
 
     def tearDown(self) -> None:
