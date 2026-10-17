Description: Compare with names bound to the cached small ints instead of
  "is" with an int literal, which is a SyntaxWarning since Python 3.8.  The
  test wants identity (EqButNotIs objects compare equal to the ints), so
  "==" would change what it checks.
Issue ID: none
Changeset: none (pyutil 3.4.1 still has it)
TODO: Submit upstream; drop once a release includes the fix.

--- pyutil/test/deprecated/test_dictutil.py.orig	2026-05-31 07:36:19 UTC
+++ pyutil/test/deprecated/test_dictutil.py
@@ -10,6 +10,10 @@ from pyutil.assertutil import _assert
 
 from pyutil import dictutil
 
+# The int objects themselves (small ints are cached), so that the tests
+# below compare by identity without a SyntaxWarning for 'is' with a literal.
+THREE, SEVEN, EIGHT = 3, 7, 8
+
 class EqButNotIs:
     def __init__(self, x):
         self.x = x
@@ -79,12 +83,12 @@ class Testy(unittest.TestCase):
         d[fake3] = fake7
         d[3] = 7
         d[3] = 8
-        # note: don't fall for the SyntaxWarning. We want 'is' and not '=='
-        _assert(any(x for x in d.values() if x is 8))
+        # note: we want 'is' and not '=='
+        _assert(any(x for x in d.values() if x is EIGHT))
         _assert(any(x for x in d.values() if x is fake7))
-        _assert(not any(x for x in d.values() if x is 7)) # The real 7 should have been ejected by the d[3] = 8.
+        _assert(not any(x for x in d.values() if x is SEVEN)) # The real 7 should have been ejected by the d[3] = 8.
         _assert(any(x for x in d if x is fake3))
-        _assert(any(x for x in d if x is 3))
+        _assert(any(x for x in d if x is THREE))
         d[fake3] = 8
 
         d.clear()
@@ -93,11 +97,11 @@ class Testy(unittest.TestCase):
         fake7 = EqButNotIs(7)
         d[fake3] = fake7
         d[3] = 8
-        _assert(any(x for x in d.values() if x is 8))
+        _assert(any(x for x in d.values() if x is EIGHT))
         _assert(any(x for x in d.values() if x is fake7))
-        _assert(not any(x for x in d.values() if x is 7)) # The real 7 should have been ejected by the d[3] = 8.
+        _assert(not any(x for x in d.values() if x is SEVEN)) # The real 7 should have been ejected by the d[3] = 8.
         _assert(any(x for x in d if x is fake3))
-        _assert(any(x for x in d if x is 3))
+        _assert(any(x for x in d if x is THREE))
         d[fake3] = 8
 
     def test_em(self):
