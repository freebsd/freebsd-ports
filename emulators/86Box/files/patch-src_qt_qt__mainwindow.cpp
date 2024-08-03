--- src/qt/qt_mainwindow.cpp.orig	2024-08-02 00:15:09 UTC
+++ src/qt/qt_mainwindow.cpp
@@ -378,6 +378,7 @@ MainWindow::MainWindow(QWidget *parent)
 
 #if QT_CONFIG(vulkan)
     bool vulkanAvailable = false;
+    if (0)
     {
         QVulkanInstance instance;
         instance.setApiVersion(QVersionNumber(1, 0));
