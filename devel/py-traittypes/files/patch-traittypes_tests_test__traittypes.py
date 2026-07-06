-- Fix compatibility with newer versions of pandas in tests
-- 
--- traittypes/tests/test_traittypes.py.orig	2026-06-11 19:38:02 UTC
+++ traittypes/tests/test_traittypes.py
@@ -166,9 +166,9 @@ class TestSeries(TestCase):
             c = Series([])
             d = Series(Undefined)
         foo = Foo()
-        self.assertTrue(foo.a.equals(pd.Series()))
+        self.assertTrue(foo.a.equals(pd.Series(dtype=foo.a.dtype)))
         self.assertTrue(foo.b is None)
-        self.assertTrue(foo.c.equals(pd.Series([])))
+        self.assertTrue(foo.c.equals(pd.Series([], dtype=foo.c.dtype)))
         self.assertTrue(foo.d is Undefined)
 
     def test_allow_none(self):
