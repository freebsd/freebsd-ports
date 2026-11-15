--- dep/XOptions/xoptions.cpp.orig	2026-11-12 21:01:22 UTC
+++ dep/XOptions/xoptions.cpp
@@ -2430,10 +2430,17 @@ QString XOptions::getApplicationDataPath()
 #endif
 #ifdef Q_OS_FREEBSD
     if (!bResult) {
-        sResult = QStandardPaths::standardLocations(QStandardPaths::GenericDataLocation).at(1) + QDir::separator() + sApplicationName;
+        const QStringList locations =
+            QStandardPaths::standardLocations(QStandardPaths::GenericDataLocation);
 
-        if (QDir(sResult).exists()) {
-            bResult = true;
+        for (const QString &location : locations) {
+            const QString candidate = QDir(location).filePath(sApplicationName);
+
+            if (QDir(candidate).exists()) {
+                sResult = candidate;
+                bResult = true;
+                break;
+            }
         }
     }
 #endif
