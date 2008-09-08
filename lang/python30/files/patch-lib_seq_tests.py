--- Lib/test/seq_tests.py.orig	2007-11-12 20:04:41.000000000 +0000
+++ Lib/test/seq_tests.py	2008-08-30 10:16:13.000000000 +0100
@@ -307,11 +307,13 @@
             self.assertEqual(id(s), id(s*1))
 
     def test_bigrepeat(self):
-        x = self.type2test([0])
-        x *= 2**16
-        self.assertRaises(MemoryError, x.__mul__, 2**16)
-        if hasattr(x, '__imul__'):
-            self.assertRaises(MemoryError, x.__imul__, 2**16)
+        import sys
+        if sys.maxint <= 2147483647:
+            x = self.type2test([0])
+            x *= 2**16
+            self.assertRaises(MemoryError, x.__mul__, 2**16)
+            if hasattr(x, '__imul__'):
+                self.assertRaises(MemoryError, x.__imul__, 2**16)
 
     def test_subscript(self):
         a = self.type2test([10, 11])
