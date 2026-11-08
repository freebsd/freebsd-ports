This failure is caused by a Python 3.12 compatibility break: assertRaisesRegexp was deprecated in Python 3.2 and fully removed in Python 3.12. It has been replaced by assertRaisesRegex.

--- pasta/augment/inline_test.py.orig	2026-09-06 13:29:54 UTC
+++ pasta/augment/inline_test.py
@@ -60,7 +60,7 @@ class InlineTest(test_utils.TestCase):
         NOT_A_CONSTANT += "bar"
         ''')
     t = ast.parse(src)
-    with self.assertRaisesRegexp(inline.InlineError,
+    with self.assertRaisesRegex(inline.InlineError,
                                  '\'NOT_A_CONSTANT\' is not a constant'):
       inline.inline_name(t, 'NOT_A_CONSTANT')
 
@@ -68,7 +68,7 @@ class InlineTest(test_utils.TestCase):
     src = 'def func(): pass\nfunc()\n'
     t = ast.parse(src)
 
-    with self.assertRaisesRegexp(
+    with self.assertRaisesRegex(
         inline.InlineError,
         '\'func\' is not a constant; it has type %r' % ast.FunctionDef):
       inline.inline_name(t, 'func')
@@ -76,14 +76,14 @@ class InlineTest(test_utils.TestCase):
   def test_inline_conditional_fails(self):
     src = 'if define:\n  x = 1\na = x\n'
     t = ast.parse(src)
-    with self.assertRaisesRegexp(inline.InlineError,
+    with self.assertRaisesRegex(inline.InlineError,
                                  '\'x\' is not a top-level name'):
       inline.inline_name(t, 'x')
 
   def test_inline_non_assign_fails(self):
     src = 'CONSTANT1, CONSTANT2 = values'
     t = ast.parse(src)
-    with self.assertRaisesRegexp(
+    with self.assertRaisesRegex(
         inline.InlineError, '\'CONSTANT1\' is not declared in an assignment'):
       inline.inline_name(t, 'CONSTANT1')
 
