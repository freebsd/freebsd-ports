--- tests/tests_clipboard/test_handlers/test_xclip.py.orig	2024-05-08 15:16:58 UTC
+++ tests/tests_clipboard/test_handlers/test_xclip.py
@@ -18,6 +18,12 @@ from normcap.clipboard.handlers import xclip
         ("linux", "", "Gnome Shell", True, True),
         ("linux", "", "", True, True),
         ("linux", "Wayland", "Gnome Wayland", False, True),
+        ("freebsd", "Wayland", "", True, True),
+        ("freebsd", "", "Gnome Wayland", True, True),
+        ("freebsd", "Wayland", "Gnome Wayland", True, True),
+        ("freebsd", "", "Gnome Shell", True, True),
+        ("freebsd", "", "", True, True),
+        ("freebsd", "Wayland", "Gnome Wayland", False, True),
         ("win32", "Wayland", "Gnome Shell", False, False),
         ("win32", "Wayland", "Gnome Wayland", True, False),
         ("darwin", "Wayland", "Gnome Wayland", True, False),
@@ -38,7 +44,7 @@ def test_xclip_is_compatible(
 
 
 @pytest.mark.skipif(not shutil.which("xclip"), reason="Needs xclip")
-@pytest.mark.skipif(sys.platform != "linux", reason="Linux specific test")
+@pytest.mark.skipif(sys.platform != "linux" and sys.platform != "freebsd", reason="Linux specific test")
 def test_xclip_copy():
     text = f"this is a unique test {uuid.uuid4()}"
 
@@ -54,7 +60,7 @@ def test_xclip_copy():
     assert text == clipped
 
 
-@pytest.mark.skipif(sys.platform == "linux", reason="Non-Linux specific test")
+@pytest.mark.skipif(sys.platform == "linux" or sys.platform == "freebsd", reason="Non-Linux specific test")
 def test_xclip_copy_on_non_linux():
     with pytest.raises((FileNotFoundError, OSError)):
         xclip.copy(text="this is a test")
