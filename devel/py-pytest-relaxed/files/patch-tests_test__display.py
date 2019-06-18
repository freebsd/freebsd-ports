# Two tests fail when warnings are present in the test run
# https://github.com/bitprophet/pytest-relaxed/issues/7

--- tests/test_display.py.orig	2019-06-14 18:05:29 UTC
+++ tests/test_display.py
@@ -18,7 +18,7 @@ def _expect_regular_output(testdir):
     assert "== FAILURES ==" in output
     assert "AssertionError" in output
     # Summary
-    assert "== 1 failed, 4 passed, 1 skipped in " in output
+    assert "== 1 failed, 4 passed, 1 skipped" in output
 
 
 class TestRegularFunctions:
@@ -170,7 +170,7 @@ OtherBehaviors
         assert "== FAILURES ==" in output
         assert "AssertionError" in output
         # Summary
-        assert "== 1 failed, 4 passed, 1 skipped in " in output
+        assert "== 1 failed, 4 passed, 1 skipped" in output
 
     def test_tests_are_colorized_by_test_result(  # noqa: F811,E501
         self, testdir, environ
@@ -225,7 +225,7 @@ OtherBehaviors
         assert "== FAILURES ==" in output
         assert "AssertionError" in output
         # Summary
-        assert "== 1 failed, 4 passed, 1 skipped in " in output
+        assert "== 1 failed, 4 passed, 1 skipped" in output
 
     def test_nests_many_levels_deep_no_problem(self, testdir):
         testdir.makepyfile(
