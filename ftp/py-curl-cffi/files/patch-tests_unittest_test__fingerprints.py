-- test_get_default_config_dir_macos does not clear XDG_CONFIG_HOME
-- before asserting the HOME-based fallback path, unlike its sibling
-- test_get_default_config_dir_linux_fallback. The FreeBSD ports
-- framework sets XDG_CONFIG_HOME via MAKE_ENV/TEST_ENV, which leaks
-- into this test and causes a deterministic failure. Add the same
-- monkeypatch.delenv() call as the sibling test.

-- Upstreamed: https://github.com/lexiforest/curl_cffi/pull/872

--- tests/unittest/test_fingerprints.py.orig	2026-09-30 07:14:01 UTC
+++ tests/unittest/test_fingerprints.py
@@ -38,6 +38,7 @@ def test_get_default_config_dir_macos(monkeypatch):
 def test_get_default_config_dir_macos(monkeypatch):
     if os.name != "posix":
         pytest.skip("POSIX default config path test")
+    monkeypatch.delenv("XDG_CONFIG_HOME", raising=False)
     monkeypatch.setenv("HOME", "/Users/tester")
 
     assert _get_default_config_dir() == "/Users/tester/.config/impersonate"
