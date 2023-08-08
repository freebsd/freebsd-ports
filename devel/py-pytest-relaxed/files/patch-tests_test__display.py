# Two tests fail when warnings are present in the test run
# https://github.com/bitprophet/pytest-relaxed/issues/7

--- tests/test_display.py.orig	2022-12-17 02:40:44 UTC
+++ tests/test_display.py
@@ -18,7 +18,7 @@ def _expect_regular_output(testdir):
     assert "== FAILURES ==" in output
     assert "AssertionError" in output
     # Summary
-    assert "== 1 failed, 4 passed, 1 skipped in " in output
+    assert "== 1 failed, 4 passed, 1 skipped" in output
 
 
 class TestRegularFunctions:
@@ -166,7 +166,7 @@ OtherBehaviors
         assert "== FAILURES ==" in output
         assert "AssertionError" in output
         # Summary
-        assert "== 1 failed, 4 passed, 1 skipped in " in output
+        assert "== 1 failed, 4 passed, 1 skipped" in output
 
     def test_tests_are_colorized_by_test_result(
         self, testdir, environ  # noqa: F811,E501
