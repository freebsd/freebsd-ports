--- src/qt/qt_mainwindow.cpp.orig	2025-08-24 12:26:31 UTC
+++ src/qt/qt_mainwindow.cpp
@@ -469,6 +469,7 @@ MainWindow::MainWindow(QWidget *parent)
 
 #if QT_CONFIG(vulkan)
     bool vulkanAvailable = false;
+    if (0)
     {
         QVulkanInstance instance;
         instance.setApiVersion(QVersionNumber(1, 0));
