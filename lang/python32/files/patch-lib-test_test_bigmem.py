--- Lib/test/test_bigmem.py.orig	2007-11-30 21:53:17.000000000 +0000
+++ Lib/test/test_bigmem.py	2008-08-30 10:16:13.000000000 +0100
@@ -1,5 +1,5 @@
 from test import test_support
-from test.test_support import bigmemtest, _1G, _2G
+from test.test_support import bigmemtest, _1G, _2G, _4G, precisionbigmemtest
 
 import unittest
 import operator
@@ -54,6 +54,22 @@
         self.assertEquals(s[lpadsize:-rpadsize], SUBSTR)
         self.assertEquals(s.strip(), SUBSTR.strip())
 
+    @precisionbigmemtest(size=_2G - 1, memuse=1)
+    def test_center_unicode(self, size):
+        SUBSTR = u' abc def ghi'
+        try:
+            s = SUBSTR.center(size)
+        except OverflowError:
+            pass # acceptable on 32-bit
+        else:
+            self.assertEquals(len(s), size)
+            lpadsize = rpadsize = (len(s) - len(SUBSTR)) // 2
+            if len(s) % 2:
+                lpadsize += 1
+            self.assertEquals(s[lpadsize:-rpadsize], SUBSTR)
+            self.assertEquals(s.strip(), SUBSTR.strip())
+            del s
+
     @bigmemtest(minsize=_2G, memuse=2)
     def test_count(self, size):
         SUBSTR = ' abc def ghi'
@@ -70,10 +86,44 @@
         s = '.' * size
         self.assertEquals(len(s.decode('utf-8')), size)
 
+    def basic_encode_test(self, size, enc, c=u'.', expectedsize=None):
+        if expectedsize is None:
+            expectedsize = size
+
+        s = c * size
+        self.assertEquals(len(s.encode(enc)), expectedsize)
+
     @bigmemtest(minsize=_2G + 2, memuse=3)
     def test_encode(self, size):
-        s = u'.' * size
-        self.assertEquals(len(s.encode('utf-8')), size)
+        return self.basic_encode_test(size, 'utf-8')
+
+    @precisionbigmemtest(size=_4G / 6 + 2, memuse=2)
+    def test_encode_raw_unicode_escape(self, size):
+        try:
+            return self.basic_encode_test(size, 'raw_unicode_escape')
+        except MemoryError:
+            pass # acceptable on 32-bit
+
+    @precisionbigmemtest(size=_4G / 5 + 70, memuse=3)
+    def test_encode_utf7(self, size):
+        try:
+            return self.basic_encode_test(size, 'utf7')
+        except MemoryError:
+            pass # acceptable on 32-bit
+
+    @precisionbigmemtest(size=_2G-1, memuse=2)
+    def test_decodeascii(self, size):
+        return self.basic_encode_test(size, 'ascii', c='A')
+
+    @precisionbigmemtest(size=_4G / 5, memuse=6+2)
+    def test_unicode_repr_oflw(self, size):
+        try:
+            s = u"\uAAAA"*size
+            r = repr(s)
+        except MemoryError:
+            pass # acceptable on 32-bit
+        else:
+            self.failUnless(s == eval(r))
 
     @bigmemtest(minsize=_2G, memuse=2)
     def test_endswith(self, size):
@@ -459,6 +509,11 @@
         self.assertEquals(s.count('\\'), size)
         self.assertEquals(s.count('0'), size * 2)
 
+    @bigmemtest(minsize=2**32 / 5, memuse=6+2)
+    def test_unicode_repr(self, size):
+        s = u"\uAAAA" * size
+        self.failUnless(len(repr(s)) > size)
+
     # This test is meaningful even with size < 2G, as long as the
     # doubled string is > 2G (but it tests more if both are > 2G :)
     @bigmemtest(minsize=_1G + 2, memuse=3)
@@ -642,6 +697,35 @@
     def test_repeat_large(self, size):
         return self.basic_test_repeat(size)
 
+    @bigmemtest(minsize=_1G - 1, memuse=12)
+    def test_repeat_large_2(self, size):
+        return self.basic_test_repeat(size)
+
+    @precisionbigmemtest(size=_1G - 1, memuse=9)
+    def test_from_2G_generator(self, size):
+        try:
+            t = tuple(xrange(size))
+        except MemoryError:
+            pass # acceptable on 32-bit
+        else:
+            count = 0
+            for item in t:
+                self.assertEquals(item, count)
+                count += 1
+            self.assertEquals(count, size)
+
+    @precisionbigmemtest(size=_1G - 25, memuse=9)
+    def test_from_almost_2G_generator(self, size):
+        try:
+            t = tuple(xrange(size))
+            count = 0
+            for item in t:
+                self.assertEquals(item, count)
+                count += 1
+            self.assertEquals(count, size)
+        except MemoryError:
+            pass # acceptable, expected on 32-bit
+
     # Like test_concat, split in two.
     def basic_test_repr(self, size):
         t = (0,) * size
@@ -957,8 +1041,34 @@
         self.assertEquals(l[:10], [1] * 10)
         self.assertEquals(l[-10:], [5] * 10)
 
+class BufferTest(unittest.TestCase):
+
+    @precisionbigmemtest(size=_1G, memuse=4)
+    def test_repeat(self, size):
+        try:
+            b = buffer("AAAA")*size
+        except MemoryError:
+            pass # acceptable on 32-bit
+        else:
+            count = 0
+            for c in b:
+                self.assertEquals(c, 'A')
+                count += 1
+            self.assertEquals(count, size*4)
+
 def test_main():
-    test_support.run_unittest(StrTest, TupleTest, ListTest)
+    test_support.run_unittest(StrTest, TupleTest, ListTest, BufferTest)
+
+# Expected failures (crashers)
+# del StrTest.test_center_unicode
+del StrTest.test_decodeascii
+# del StrTest.test_encode_utf32
+# del StrTest.test_encode_utf7
+# del StrTest.test_encode_raw_unicode_escape
+#
+# del TupleTest.test_from_2G_generator
+#
+# del BufferTest.test_repeat
 
 if __name__ == '__main__':
     if len(sys.argv) > 1:
