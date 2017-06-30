--- test_pytest_mock.py.orig	2017-06-25 15:24:57 UTC
+++ test_pytest_mock.py
@@ -100,25 +100,6 @@ def test_mock_patch_dict(mocker):
     assert x == {'original': 1}
 
 
-def test_mock_fixture_is_deprecated(testdir):
-    """
-    Test that a warning emitted when using deprecated "mock" fixture.
-    """
-    testdir.makepyfile('''
-        import warnings
-        import os
-        warnings.simplefilter('always')
-
-        def test_foo(mock, tmpdir):
-            mock.patch('os.listdir', return_value=['mocked'])
-            assert os.listdir(str(tmpdir)) == ['mocked']
-            mock.stopall()
-            assert os.listdir(str(tmpdir)) == []
-    ''')
-    result = testdir.runpytest('-s')
-    result.stderr.fnmatch_lines(['*"mock" fixture has been deprecated*'])
-
-
 def test_deprecated_mock(mock, tmpdir):
     """
     Use backward-compatibility-only mock fixture to ensure complete coverage.
