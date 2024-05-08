Fix build on FreeBSD 13.2

In file included from /wrkdirs/usr/ports/deskutils/plasma6-xdg-desktop-portal-kde/work/.build/src/xdg-desktop-portal-kde_autogen/mocs_compilation.cpp:29:
In file included from /wrkdirs/usr/ports/deskutils/plasma6-xdg-desktop-portal-kde/work/.build/src/xdg-desktop-portal-kde_autogen/EWIEGA46WW/moc_session.cpp:9:
/wrkdirs/usr/ports/deskutils/plasma6-xdg-desktop-portal-kde/work/.build/src/xdg-desktop-portal-kde_autogen/EWIEGA46WW/../../../../xdg-desktop-portal-kde-6.0.4/src/session.h:186:10: error: no template named 'unordered_map' in namespace 'std'
    std::unordered_map<QString, std::unique_ptr<QAction>> m_shortcuts;
    ~~~~~^

--- src/session.h.orig	2024-04-16 10:39:21 UTC
+++ src/session.h
@@ -9,6 +9,8 @@
 #ifndef XDG_DESKTOP_PORTAL_KDE_SESSION_H
 #define XDG_DESKTOP_PORTAL_KDE_SESSION_H
 
+#include <unordered_map>
+
 #include <QAction>
 #include <QDBusVirtualObject>
 #include <QObject>
