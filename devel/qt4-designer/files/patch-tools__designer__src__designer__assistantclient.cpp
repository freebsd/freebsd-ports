--- ./tools/designer/src/designer/assistantclient.cpp.orig	2008-04-28 17:11:20.000000000 +0400
+++ ./tools/designer/src/designer/assistantclient.cpp	2008-06-17 01:30:25.000000000 +0400
@@ -115,7 +115,7 @@
 {
     QString app = QLibraryInfo::location(QLibraryInfo::BinariesPath) + QDir::separator();
 #if !defined(Q_OS_MAC)
-    app += QLatin1String("assistant");
+    app += QLatin1String("assistant-qt4");
 #else
     app += QLatin1String("Assistant.app/Contents/MacOS/Assistant");    
 #endif
