--- tests/tests_clipboard/test_handlers/test_wlclipboard.py.orig	2024-05-07 18:10:18 UTC
+++ tests/tests_clipboard/test_handlers/test_wlclipboard.py
@@ -18,6 +18,12 @@ from normcap.clipboard.handlers import wlclipboard
         ("linux", "Wayland", "Gnome Wayland", "45.1", False),
         ("linux", "", "Gnome Shell", "44", False),
         ("linux", "", "", "44", False),
+        ("freebsd", "Wayland", "", "44", True),
+        ("freebsd", "", "Gnome Wayland", "44", True),
+        ("freebsd", "Wayland", "Gnome Wayland", "44", True),
+        ("freebsd", "Wayland", "Gnome Wayland", "45.1", False),
+        ("freebsd", "", "Gnome Shell", "44", False),
+        ("freebsd", "", "", "44", False),
         ("win32", "Wayland", "Gnome Wayland", "", False),
         ("darwin", "Wayland", "Gnome Wayland", "", False),
     ],
@@ -38,6 +44,8 @@ def test_wlcopy_is_compatible(
     [
         ("linux", True, True),
         ("linux", False, False),
+        ("freebsd", True, True),
+        ("freebsd", False, False),
     ],
 )
 def test_wlcopy_is_installed(platform, has_wlcopy, result, monkeypatch):
@@ -53,7 +61,7 @@ def test_wlcopy_is_installed(platform, has_wlcopy, res
 # see https://github.com/bugaevc/wl-clipboard/issues/168
 @pytest.mark.skipif(True, reason="Buggy in Gnome 45")
 @pytest.mark.skipif(not shutil.which("wl-copy"), reason="Needs wl-copy")
-@pytest.mark.skipif(sys.platform != "linux", reason="Linux specific test")
+@pytest.mark.skipif(sys.platform != "linux" and sys.platform != "freebsd", reason="Linux specific test")
 def test_wlcopy_copy():
     text = f"this is a unique test {uuid.uuid4()}"
 
@@ -70,7 +78,7 @@ def test_wlcopy_copy():
 
 
 @pytest.mark.skipif(True, reason="Buggy in Gnome 45")
-@pytest.mark.skipif(sys.platform == "linux", reason="Non-Linux specific test")
+@pytest.mark.skipif(sys.platform == "linux" or sys.platform == "freebsd", reason="Non-Linux specific test")
 def test_wlcopy_copy_on_non_linux():
     with pytest.raises((FileNotFoundError, OSError)):
         wlclipboard.copy(text="this is a test")
