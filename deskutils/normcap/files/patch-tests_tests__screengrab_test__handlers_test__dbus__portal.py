--- tests/tests_screengrab/test_handlers/test_dbus_portal.py.orig	2024-05-08 15:04:22 UTC
+++ tests/tests_screengrab/test_handlers/test_dbus_portal.py
@@ -8,7 +8,7 @@ from normcap.screengrab.permissions import has_screens
 
 
 @pytest.mark.gui()
-@pytest.mark.skipif(sys.platform != "linux", reason="Linux specific test")
+@pytest.mark.skipif((sys.platform != "linux" and sys.platform != "freebsd"), reason="Linux specific test")
 @pytest.mark.skipif("GITHUB_ACTIONS" in os.environ, reason="Skip on Action Runner")
 def test_synchronized_capture(dbus_portal, qapp):
     if not has_screenshot_permission():
@@ -20,7 +20,7 @@ def test_synchronized_capture(dbus_portal, qapp):
 
 
 @pytest.mark.gui()
-@pytest.mark.skipif(sys.platform != "linux", reason="Linux specific test")
+@pytest.mark.skipif((sys.platform != "linux" and sys.platform != "freebsd"), reason="Linux specific test")
 def test_synchronized_capture_triggers_request_error(monkeypatch, dbus_portal):
     def _mocked_interface_call(*args):
         return dbus_portal.QtDBus.QDBusMessage()
@@ -33,7 +33,7 @@ def test_synchronized_capture_triggers_request_error(m
 
 
 @pytest.mark.gui()
-@pytest.mark.skipif(sys.platform != "linux", reason="Linux specific test")
+@pytest.mark.skipif((sys.platform != "linux" and sys.platform != "freebsd"), reason="Linux specific test")
 @pytest.mark.skipif("GITHUB_ACTIONS" in os.environ, reason="Skip on Action Runner")
 def test_synchronized_capture_triggers_response_error(monkeypatch, dbus_portal):
     def _decorated_got_signal(method):
@@ -55,7 +55,7 @@ def test_synchronized_capture_triggers_response_error(
 
 
 @pytest.mark.gui()
-@pytest.mark.skipif(sys.platform != "linux", reason="Linux specific test")
+@pytest.mark.skipif((sys.platform != "linux" and sys.platform != "freebsd"), reason="Linux specific test")
 def test_synchronized_capture_triggers_timeout(monkeypatch, dbus_portal):
     timeout = 1
     monkeypatch.setattr(dbus_portal, "TIMEOUT_SECONDS", timeout)
