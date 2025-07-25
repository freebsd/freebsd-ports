Add QWaylandShellSurface::nativeResource() to allow using it instead of
surfaceRole(). The problem with latter is that it relies on RTTI, which is not
stable across shared modules loaded with RTLD_LOCAL.

x11/plasma6-layer-shell-qt calls into this private API and crashes. Linux/GCC
users are not seeing this because libstdc++ use different algorithm for comparing
RTTI. Our libc++ can be switched to this algorithm too by building with
-DLIBCXX_TYPEINFO_COMPARISON_IMPLEMENTATION=2, but this is too drastic approach.

Related URLs:
* https://bugs.kde.org/show_bug.cgi?id=479679
* https://github.com/llvm/llvm-project/issues/36746

--- src/client/qwaylandshellsurface_p.h.orig	2025-05-29 00:19:49 UTC
+++ src/client/qwaylandshellsurface_p.h
@@ -85,6 +85,7 @@ class Q_WAYLANDCLIENT_EXPORT QWaylandShellSurface : pu
     QPlatformWindow *platformWindow();
     struct wl_surface *wlSurface();
 
+    virtual void* nativeResource(const QByteArray&) { return nullptr; }
     virtual std::any surfaceRole() const { return std::any(); };
 
     virtual void attachPopup(QWaylandShellSurface *popup) { Q_UNUSED(popup); }
