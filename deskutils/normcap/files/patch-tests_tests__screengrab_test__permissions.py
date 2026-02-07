--- tests/tests_screengrab/test_permissions.py.orig	2024-05-08 15:23:15 UTC
+++ tests/tests_screengrab/test_permissions.py
@@ -7,7 +7,7 @@ from normcap.screengrab import permissions
 from normcap.screengrab import permissions
 
 
-@pytest.mark.skipif(sys.platform in {"win32", "linux"}, reason="macOS specific test")
+@pytest.mark.skipif(sys.platform in {"win32", "linux", "freebsd"}, reason="macOS specific test")
 def test_macos_has_screenshot_permission(caplog):
     with caplog.at_level(logging.WARNING):
         result = permissions._macos_has_screenshot_permission()
@@ -22,7 +22,7 @@ def test_macos_has_screenshot_permission_on_non_macos(
     assert result is True
 
 
-@pytest.mark.skipif(sys.platform in {"win32", "linux"}, reason="macOS specific test")
+@pytest.mark.skipif(sys.platform in {"win32", "linux", "freebsd"}, reason="macOS specific test")
 def test_macos_request_screenshot_permission(caplog):
     with caplog.at_level(logging.DEBUG):
         permissions._macos_request_screenshot_permission()
@@ -36,7 +36,7 @@ def test_macos_request_screenshot_permission_on_non_ma
     assert "couldn't request" in caplog.text.lower()
 
 
-@pytest.mark.skipif(sys.platform in {"win32", "linux"}, reason="macOS specific test")
+@pytest.mark.skipif(sys.platform in {"win32", "linux", "freebsd"}, reason="macOS specific test")
 def test_macos_reset_screenshot_permission(caplog):
     with caplog.at_level(logging.ERROR):
         permissions.macos_reset_screenshot_permission()
@@ -72,14 +72,14 @@ def test_has_screenshot_permission_raises(monkeypatch,
         _ = permissions.has_screenshot_permission()
 
 
-@pytest.mark.skipif(sys.platform in {"win32", "linux"}, reason="macOS specific test")
+@pytest.mark.skipif(sys.platform in {"win32", "linux", "freebsd"}, reason="macOS specific test")
 def test_macos_open_privacy_settings(caplog):
     with caplog.at_level(logging.ERROR):
         permissions._macos_open_privacy_settings()
     assert "couldn't open" not in caplog.text.lower()
 
 
-@pytest.mark.skipif(sys.platform in {"win32", "linux"}, reason="macOS specific test")
+@pytest.mark.skipif(sys.platform in {"win32", "linux", "freebsd"}, reason="macOS specific test")
 def test_macos_open_privacy_settings_logs_exception(monkeypatch, caplog):
     def mocked_run(*_, **__):
         raise ValueError("Mocked exception on 'open' call")
