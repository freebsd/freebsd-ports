-- Treat FreeBSD like Linux when obtaining the Qt X11 surface info,
-- otherwise creating windowed Qt canvases fails on FreeBSD.
-- Not reported upstream yet.
-- upstreamed: https://github.com/pygfx/rendercanvas/pull/259

--- rendercanvas/qt.py.orig	2026-11-16 10:15:05 UTC
+++ rendercanvas/qt.py
@@ -384,7 +384,7 @@ class QRenderWidget(BaseRenderCanvas, QtWidgets.QWidge
             return {
                 "window": int(self.winId()),
             }
-        elif sys.platform.startswith("linux"):
+        elif sys.platform.startswith(("linux", "freebsd")):
             # Note that the platform to target is decided by Qt (the qpa
             # plugin), not by the session: under a Wayland session Qt may well
             # be running on XWayland, in which case winId() is an X11 window.
