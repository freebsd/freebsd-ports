--- src/app/qbs-setup-qt/setupqt.cpp.orig	2021-11-28 22:25:29 UTC
+++ src/app/qbs-setup-qt/setupqt.cpp
@@ -70,7 +70,7 @@ static QStringList qmakeExecutableNames()
 {
     const QString baseName = HostOsInfo::appendExecutableSuffix(QStringLiteral("qmake"));
     QStringList lst(baseName);
-    if (HostOsInfo::isLinuxHost()) {
+    if (true || HostOsInfo::isLinuxHost()) {
         // Some distributions ship binaries called qmake-qt5 or qmake-qt4.
         lst << baseName + QLatin1String("-qt5") << baseName + QLatin1String("-qt4");
     }
