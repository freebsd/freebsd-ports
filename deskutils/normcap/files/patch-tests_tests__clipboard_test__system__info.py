--- tests/tests_clipboard/test_system_info.py.orig	2024-05-07 18:10:18 UTC
+++ tests/tests_clipboard/test_system_info.py
@@ -10,6 +10,10 @@ from normcap.clipboard import system_info
         ("wayland", "", "linux", True),
         ("", "wayland", "linux", True),
         ("", "", "linux", False),
+        ("wayland", "wayland", "freebsd", True),
+        ("wayland", "", "freebsd", True),
+        ("", "wayland", "freebsd", True),
+        ("", "", "freebsd", False),
         ("wayland", "wayland", "win32", False),
         ("wayland", "wayland", "darwin", False),
     ],
@@ -29,6 +33,8 @@ def test_os_has_wayland_display_manager(
     [
         ("linux", "awesome", True),
         ("linux", "gnome", False),
+        ("freebsd", "awesome", True),
+        ("freebsd", "gnome", False),
         ("win32", "awesome", False),
         ("darwin", "awesome", False),
     ],
@@ -45,6 +51,8 @@ def test_os_has_awesome_wm(monkeypatch, platform, desk
     [
         ("linux", "gnome", "gnome", "/usr/bin/gnome-shell", "33.3.0"),
         ("linux", "kde", "", "/usr/bin/gnome-shell", ""),
+        ("freebsd", "gnome", "gnome", "/usr/local/bin/gnome-shell", "33.3.0"),
+        ("freebsd", "kde", "", "/usr/local/bin/gnome-shell", ""),
         ("darwin", "", "", "", ""),
         ("darwin", "", "", "/usr/bin/gnome-shell", ""),
         ("win32", "", "", "", ""),
