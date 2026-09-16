--- syncthingtray/plasmoid/lib/syncthingapplet.h.orig	2026-09-13 15:05:04 UTC
+++ syncthingtray/plasmoid/lib/syncthingapplet.h
@@ -83,7 +83,9 @@ class SyncthingApplet : public Plasma::Applet {
             currentConnectionConfigIndexChanged)
     Q_PROPERTY(int defaultTab READ defaultTab CONSTANT)
     Q_PROPERTY(bool startStopEnabled READ isStartStopEnabled NOTIFY settingsChanged)
+#ifdef LIB_SYNCTHING_CONNECTOR_SUPPORT_SYSTEMD
     Q_PROPERTY(QObject *startStopButtonTarget READ service CONSTANT)
+#endif
     Q_PROPERTY(bool hasInternalErrors READ hasInternalErrors NOTIFY hasInternalErrorsChanged)
     Q_PROPERTY(QSize size READ size WRITE setSize NOTIFY sizeChanged)
     Q_PROPERTY(bool showTabTexts READ isShowingTabTexts WRITE setShowingTabTexts NOTIFY showTabTextsChanged)
@@ -113,7 +115,9 @@ class SyncthingApplet : public Plasma::Applet {
 #if defined(SYNCTHINGWIDGETS_GUI_QTQUICK_MODE_DESKTOP)
     QtGui::QuickUI *quickUI() const;
 #endif
+#ifdef LIB_SYNCTHING_CONNECTOR_SUPPORT_SYSTEMD
     Data::SyncthingService *service() const;
+#endif
     QIcon syncthingIcon() const;
     QString incomingTraffic() const;
     bool hasIncomingTraffic() const;
@@ -283,14 +287,12 @@ inline QtGui::QuickUI *SyncthingApplet::quickUI() cons
 }
 #endif
 
+#ifdef LIB_SYNCTHING_CONNECTOR_SUPPORT_SYSTEMD
 inline Data::SyncthingService *SyncthingApplet::service() const
 {
-#ifdef LIB_SYNCTHING_CONNECTOR_SUPPORT_SYSTEMD
     return const_cast<Data::SyncthingService *>(&m_service);
-#else
-    return nullptr;
-#endif
 }
+#endif
 
 inline int SyncthingApplet::currentConnectionConfigIndex() const
 {
