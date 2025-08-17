Don't globally install color palettes only used by this application.

Ref: https://invent.kde.org/graphics/kolourpaint/-/merge_requests/79

--- lgpl/generic/kpColorCollection.cpp.orig	2025-08-07 03:21:56 UTC
+++ lgpl/generic/kpColorCollection.cpp
@@ -80,7 +80,7 @@ QStringList kpColorCollection::installedCollections()
 {
     QStringList paletteList;
 
-    QStringList paths = QStandardPaths::locateAll(QStandardPaths::GenericConfigLocation, QStringLiteral("colors"), QStandardPaths::LocateDirectory);
+    QStringList paths = QStandardPaths::locateAll(QStandardPaths::AppDataLocation, QStringLiteral("colors"), QStandardPaths::LocateDirectory);
     for (const auto &path : paths) {
         paletteList.append(QDir(path).entryList(QStringList(), QDir::Files));
     }
@@ -206,7 +206,7 @@ bool kpColorCollection::openKDE(const QString &name, Q
         return false;
     }
 
-    QString filename = QStandardPaths::locate(QStandardPaths::GenericConfigLocation, QStringLiteral("colors/") + name);
+    QString filename = QStandardPaths::locate(QStandardPaths::AppDataLocation, QStringLiteral("colors/") + name);
     if (filename.isEmpty()) {
 #if DEBUG_KP_COLOR_COLLECTION
         qCDebug(kpLogColorCollection) << "could not find file";
