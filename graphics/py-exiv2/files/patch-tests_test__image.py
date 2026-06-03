-- Skip test_BMFF if image_02.heic is missing from the source distribution.

--- tests/test_image.py.orig	2026-05-15 06:48:44 UTC
+++ tests/test_image.py
@@ -39,6 +39,8 @@ class TestImageModule(unittest.TestCase):
         self.assertEqual(result, expected_value)
 
     def test_BMFF(self):
+        if not os.path.exists(self.bmff_path):
+            self.skipTest("missing test file")
         with self.assertWarns(DeprecationWarning):
             enabled = exiv2.enableBMFF(True)
         self.assertEqual(enabled, exiv2.versionInfo()['EXV_ENABLE_BMFF'])
