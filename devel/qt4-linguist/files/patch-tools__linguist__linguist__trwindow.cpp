--- ./tools/linguist/linguist/trwindow.cpp.orig	2008-04-28 17:11:21.000000000 +0400
+++ ./tools/linguist/linguist/trwindow.cpp	2008-06-17 01:02:02.000000000 +0400
@@ -939,7 +939,7 @@
     if (m_assistantProcess->state() != QProcess::Running) {
         QString app = QLibraryInfo::location(QLibraryInfo::BinariesPath) + QDir::separator();
 #if !defined(Q_OS_MAC)
-        app += QLatin1String("assistant");
+        app += QLatin1String("assistant-qt4");
 #else
         app += QLatin1String("Assistant.app/Contents/MacOS/Assistant");
 #endif
