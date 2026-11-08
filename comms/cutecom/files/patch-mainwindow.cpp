--- mainwindow.cpp.orig	2023-12-19 18:46:28 UTC
+++ mainwindow.cpp
@@ -881,7 +881,7 @@ void MainWindow::sendFile()
         QStringList listProcessArgs;
         listProcessArgs.append("-c");
 
-        QString tmp = QString("sz ");
+        QString tmp = QString("lsz ");
         switch (protocol) {
         case Settings::XMODEM:
             tmp += "--xmodem";
