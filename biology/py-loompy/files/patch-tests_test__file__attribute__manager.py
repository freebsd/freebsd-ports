-- Fix tests for FreeBSD (don't delete temporary files on close, fix np.int).

--- tests/test_file_attribute_manager.py.orig	2026-06-08 10:21:32 UTC
+++ tests/test_file_attribute_manager.py
@@ -12,7 +12,7 @@ class GlobalAttributeManagerTests(TestCase):
 	VALUE_IN_FILE = np.arange(3)
 
 	def setUp(self):
-		f = NamedTemporaryFile(suffix="loom")
+		f = NamedTemporaryFile(suffix="loom", delete=False)
 		f.close()
 		self.filename = f.name
 		self.file = h5py.File(f.name)
