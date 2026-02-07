--- src/json.cpp.orig	2022-02-20 12:59:53 UTC
+++ src/json.cpp
@@ -36,7 +36,7 @@ bool MainWindow::json_Read(Config trail)
 {
    bool ok = true;
 
-   m_appPath = QCoreApplication::applicationDirPath();
+   m_appPath = DIAMOND_SHARE_DIR; // QCoreApplication::applicationDirPath();
 
    QSettings settings("Diamond Editor", "Settings");
    m_jsonFname = settings.value("configName").toString();
