--- Lib/test/test_zlib.py	2008/04/08 23:47:30	62234
+++ Lib/test/test_zlib.py	2008/04/09 00:25:17	62235
@@ -83,6 +83,11 @@
         # verify failure on building decompress object with bad params
         self.assertRaises(ValueError, zlib.decompressobj, 0)
 
+    def test_decompressobj_badflush(self):
+        # verify failure on calling decompressobj.flush with bad params
+        self.assertRaises(ValueError, zlib.decompressobj().flush, 0)
+        self.assertRaises(ValueError, zlib.decompressobj().flush, -1)
+
 
 
 class CompressTestCase(unittest.TestCase):
