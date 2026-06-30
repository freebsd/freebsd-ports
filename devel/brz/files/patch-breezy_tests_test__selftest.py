--- breezy/tests/test_selftest.py.orig	2021-12-07 02:24:26 UTC
+++ breezy/tests/test_selftest.py
@@ -1249,8 +1249,8 @@ class TestRunner(tests.TestCase):
     def test_verbose_test_count(self):
         """A verbose test run reports the right test count at the start"""
         suite = TestUtil.TestSuite([
-            unittest.FunctionTestCase(lambda:None),
-            unittest.FunctionTestCase(lambda:None)])
+            unittest.FunctionTestCase(lambda: None),
+            unittest.FunctionTestCase(lambda: None)])
         self.assertEqual(suite.countTestCases(), 2)
         stream = StringIO()
         runner = tests.TextTestRunner(stream=stream, verbosity=2)
