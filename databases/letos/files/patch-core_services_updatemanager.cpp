-- Fix build on FreeBSD: jsonQString() is undefined for non-Windows/Linux/macOS platforms.
-- Use an empty QString() instead, since there is no binary download URL for FreeBSD.
-- reported upstream: https://github.com/pawelsalawa/letos/issues/5840

--- core/services/updatemanager.cpp.orig	2026-11-05 02:57:51 UTC
+++ core/services/updatemanager.cpp
@@ -93,7 +93,7 @@ void UpdateManager::handleUpdatesResponse(QNetworkRepl
 #elif defined(Q_OS_OSX)
     QString url = json["mac"].toString();
 #else
-    QString url = jsonQString();
+    QString url = QString();
 #endif
 
     emit updateAvailable(version, url);
