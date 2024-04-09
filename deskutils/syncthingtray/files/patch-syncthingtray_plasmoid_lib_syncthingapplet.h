--- syncthingtray/plasmoid/lib/syncthingapplet.h.orig	2024-04-02 09:09:30 UTC
+++ syncthingtray/plasmoid/lib/syncthingapplet.h
@@ -61,7 +61,9 @@ class SyncthingApplet : public Plasma::Applet {
     Q_PROPERTY(Data::SyncthingDownloadModel *downloadModel READ downloadModel NOTIFY downloadModelChanged)
     Q_PROPERTY(Data::SyncthingRecentChangesModel *recentChangesModel READ recentChangesModel NOTIFY recentChangesModelChanged)
     Q_PROPERTY(Data::SyncthingStatusSelectionModel *passiveSelectionModel READ passiveSelectionModel NOTIFY passiveSelectionModelChanged)
+#ifdef LIB_SYNCTHING_CONNECTOR_SUPPORT_SYSTEMD
     Q_PROPERTY(Data::SyncthingService *service READ service NOTIFY serviceChanged)
+#endif
     Q_PROPERTY(bool local READ isLocal NOTIFY localChanged)
     Q_PROPERTY(QString statusText READ statusText NOTIFY connectionStatusChanged)
     Q_PROPERTY(QString additionalStatusText READ additionalStatusText NOTIFY connectionStatusChanged)
