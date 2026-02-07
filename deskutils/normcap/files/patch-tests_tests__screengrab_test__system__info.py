--- tests/tests_screengrab/test_system_info.py.orig	2024-05-08 15:20:50 UTC
+++ tests/tests_screengrab/test_system_info.py
@@ -10,6 +10,7 @@ def test_display_manager_is_wayland_on_windows(monkeyp
     assert is_wayland is False
 
 
+@pytest.mark.skipif(sys.platform not in {"linux", "freebsd"}, reason="Linux/FreeBSD specific test")
 def test_display_manager_is_wayland_on_linux_xdg_session_type(monkeypatch):
     monkeypatch.setattr(system_info.sys, "platform", "linux")
 
@@ -35,6 +36,7 @@ def test_gnome_version_on_windows(monkeypatch):
     assert not version
 
 
+@pytest.mark.skipif(sys.platform not in {"linux", "freebsd"}, reason="Linux/FreeBSD specific test")
 def test_gnome_version_on_linux_from_cmd(monkeypatch):
     monkeypatch.setattr(system_info.sys, "platform", "linux")
     monkeypatch.setenv("GNOME_DESKTOP_SESSION_ID", "")
@@ -55,6 +57,7 @@ def test_gnome_version_on_linux_from_cmd(monkeypatch):
     assert str(version) == "33.3"
 
 
+@pytest.mark.skipif(sys.platform not in {"linux", "freebsd"}, reason="Linux/FreeBSD specific test")
 def test_gnome_version_on_linux_without_gnome_shell(monkeypatch):
     monkeypatch.setattr(system_info.sys, "platform", "linux")
     monkeypatch.setenv("GNOME_DESKTOP_SESSION_ID", "")
@@ -70,6 +73,7 @@ def test_gnome_version_on_linux_without_gnome_shell(mo
     assert not version
 
 
+@pytest.mark.skipif(sys.platform not in {"linux", "freebsd"}, reason="Linux/FreeBSD specific test")
 def test_gnome_version_on_linux_unknown_exception(monkeypatch, caplog):
     monkeypatch.setattr(system_info.sys, "platform", "linux")
     monkeypatch.setattr(system_info.shutil, "which", lambda _: True)
