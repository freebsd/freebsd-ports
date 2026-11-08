-- Allow FreeBSD in the X11/Wayland display helpers, which assert that the
-- platform is Linux; FreeBSD uses the same X11/Wayland client libraries.
-- Not reported upstream yet.
-- upstreamed: https://github.com/pygfx/rendercanvas/pull/259

--- rendercanvas/core/coreutils.py.orig	2026-10-19 13:05:15 UTC
+++ rendercanvas/core/coreutils.py
@@ -377,7 +377,7 @@ def get_alt_x11_display():
     # But this is not always possible. In that case, using an alt display
     # object can be used.
     global _x11_display
-    assert sys.platform.startswith("linux")
+    assert sys.platform.startswith(("linux", "freebsd"))
     if _x11_display is None:
         x11 = ctypes.CDLL(ctypes.util.find_library("X11"))
         x11.XOpenDisplay.restype = ctypes.c_void_p
@@ -395,7 +395,7 @@ def get_alt_wayland_display():
     # Unfortunately, this segfaults, so it looks like the real display object
     # is needed? Leaving this here for reference.
     global _wayland_display
-    assert sys.platform.startswith("linux")
+    assert sys.platform.startswith(("linux", "freebsd"))
     if _wayland_display is None:
         wl = ctypes.CDLL(ctypes.util.find_library("wayland-client"))
         wl.wl_display_connect.restype = ctypes.c_void_p
