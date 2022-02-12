Avoid hardcoded Python binary.

--- testing/test_integration.py.orig	2022-02-10 17:16:34 UTC
+++ testing/test_integration.py
@@ -119,7 +119,7 @@ def test_pretend_version_accepts_bad_string(monkeypatc
     monkeypatch.setenv(PRETEND_KEY, "dummy")
     wd.write("setup.py", SETUP_PY_PLAIN)
     assert wd.get_version(write_to="test.py") == "dummy"
-    assert wd("python setup.py --version") == "0.0.0"
+    assert wd("%%PYTHON_CMD%% setup.py --version") == "0.0.0"
 
 
 def test_own_setup_fails_on_old_python(monkeypatch):
