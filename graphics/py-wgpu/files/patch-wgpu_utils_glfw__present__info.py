-- Treat FreeBSD like Linux when building GLFW present info (X11/Wayland),
-- otherwise it raises "Cannot get GLFW surface info" on FreeBSD.
-- Not reported upstream.

--- wgpu/utils/glfw_present_info.py.orig	2026-10-19 13:06:19 UTC
+++ wgpu/utils/glfw_present_info.py
@@ -13,7 +13,7 @@ def get_glfw_present_info(window, vsync=True) -> dict:
 
     system_is_wayland = "wayland" in os.getenv("XDG_SESSION_TYPE", "").lower()
     api_is_wayland = False
-    if sys.platform.startswith("linux") and system_is_wayland:
+    if sys.platform.startswith(("linux", "freebsd")) and system_is_wayland:
         if not hasattr(glfw, "get_x11_window"):
             api_is_wayland = True
 
@@ -29,7 +29,7 @@ def get_glfw_present_info(window, vsync=True) -> dict:
             "window": int(glfw.get_cocoa_window(window)),
             "vsync": vsync,
         }
-    elif sys.platform.startswith("linux"):
+    elif sys.platform.startswith(("linux", "freebsd")):
         if api_is_wayland:
             return {
                 "platform": "wayland",
