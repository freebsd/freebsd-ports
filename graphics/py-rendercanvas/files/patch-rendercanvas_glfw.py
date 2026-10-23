-- Treat FreeBSD like Linux when obtaining the GLFW window surface info
-- (X11/Wayland), otherwise creating windowed canvases fails on FreeBSD.
-- Not reported upstream yet.
-- upstreamed: https://github.com/pygfx/rendercanvas/pull/259

--- rendercanvas/glfw.py.orig	2026-10-19 13:05:15 UTC
+++ rendercanvas/glfw.py
@@ -125,7 +125,7 @@ def get_glfw_present_info(window):
             "window": int(glfw.get_cocoa_window(window)),
         }
 
-    elif sys.platform.startswith("linux"):
+    elif sys.platform.startswith(("linux", "freebsd")):
         # When the respective platform (X11 or Wayland) is not initialized, glfw emits a GLFWError warning and returns None. We treat None as "backend not active" here so that the warning carries no actionable information for the caller.
         with warnings.catch_warnings():
             warnings.simplefilter("ignore", glfw.GLFWError)
