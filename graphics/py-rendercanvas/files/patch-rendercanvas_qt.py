-- Treat FreeBSD like Linux when obtaining the Qt X11 surface info,
-- otherwise creating windowed Qt canvases fails on FreeBSD.
-- Not reported upstream yet.
-- upstreamed: https://github.com/pygfx/rendercanvas/pull/259

--- rendercanvas/qt.py.orig	2026-10-19 13:05:15 UTC
+++ rendercanvas/qt.py
@@ -309,7 +309,7 @@ class QRenderWidget(BaseRenderCanvas, QtWidgets.QWidge
             return {
                 "window": int(self.winId()),
             }
-        elif sys.platform.startswith("linux"):
+        elif sys.platform.startswith(("linux", "freebsd")):
             if False:
                 # We fall back to XWayland, see coreutils.py
                 return {
