--- src/MainWindow/MainWindow.h.orig	2021-01-11 09:41:28 UTC
+++ src/MainWindow/MainWindow.h
@@ -146,7 +146,9 @@ class MainWindow : public QMainWindow {
     void on_normalSizeAct_triggered();
     void updateMagnificationButtons(GenericViewer *);
 
+#ifdef WITH_HELPBROWSER
     void on_documentationAction_triggered();
+#endif
     void enterWhatsThis();
 
     void on_OptionsAction_triggered();
@@ -180,7 +182,9 @@ class MainWindow : public QMainWindow {
     void enableCrop(bool);
     void disableCrop();
 
+#ifdef WITH_HELPBROWSER
     void helpBrowserClosed();
+#endif
     void on_actionDonate_triggered();
 
     void onUpdateAvailable();
