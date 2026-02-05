Companion change to patch-src_plugins_shellintegration_xdg-shell_qwaylandxdgshell__p.h

--- src/plugins/platforms/wayland/plugins/shellintegration/xdg-shell/qwaylandxdgshell_p.h.orig	2026-01-13 10:18:17 UTC
+++ src/plugins/platforms/wayland/plugins/shellintegration/xdg-shell/qwaylandxdgshell_p.h
@@ -62,7 +62,7 @@ class Q_WAYLANDCLIENT_EXPORT QWaylandXdgSurface : publ
 
     void setSizeHints();
 
-    void *nativeResource(const QByteArray &resource);
+    void *nativeResource(const QByteArray &resource) override;
 
     std::any surfaceRole() const override;
 
