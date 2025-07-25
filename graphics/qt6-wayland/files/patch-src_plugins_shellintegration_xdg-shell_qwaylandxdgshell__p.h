Companion change to patch-src_plugins_shellintegration_xdg-shell_qwaylandxdgshell__p.h

--- src/plugins/shellintegration/xdg-shell/qwaylandxdgshell_p.h.orig	2025-05-29 00:19:49 UTC
+++ src/plugins/shellintegration/xdg-shell/qwaylandxdgshell_p.h
@@ -75,7 +75,7 @@ class Q_WAYLANDCLIENT_EXPORT QWaylandXdgSurface : publ
 
     void setSizeHints();
 
-    void *nativeResource(const QByteArray &resource);
+    void *nativeResource(const QByteArray &resource) override;
 
     std::any surfaceRole() const override;
 
