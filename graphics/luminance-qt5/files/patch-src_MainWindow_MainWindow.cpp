--- src/MainWindow/MainWindow.cpp.orig	2021-01-11 09:41:28 UTC
+++ src/MainWindow/MainWindow.cpp
@@ -99,7 +99,9 @@
 #include <HdrWizard/AutoAntighosting.h>
 #include <HdrWizard/HdrWizard.h>
 #include <HdrWizard/WhiteBalance.h>
+#ifdef WITH_HELPBROWSER
 #include <HelpBrowser/helpbrowser.h>
+#endif
 #include <LibpfsAdditions/formathelper.h>
 #include <Preferences/PreferencesDialog.h>
 #include <PreviewPanel/PreviewPanel.h>
@@ -209,7 +211,9 @@ int MainWindow::sm_counter = 0;
 QMap<int, MainWindow *> MainWindow::sm_mainWindowMap =
     QMap<int, MainWindow *>();
 QScopedPointer<UpdateChecker> MainWindow::sm_updateChecker;
+#ifdef WITH_HELPBROWSER
 HelpBrowser *MainWindow::sm_helpBrowser = nullptr;
+#endif
 
 MainWindow::MainWindow(QWidget *parent)
     : QMainWindow(parent),
@@ -1060,6 +1064,7 @@ void MainWindow::on_normalSizeAct_triggered() {
 }
 // Zoom = Viewers (END)
 
+#ifdef WITH_HELPBROWSER
 void MainWindow::on_documentationAction_triggered() {
     if (sm_helpBrowser == nullptr) {
         sm_helpBrowser =
@@ -1080,6 +1085,7 @@ void MainWindow::on_documentationAction_triggered() {
 void MainWindow::helpBrowserClosed() {
     sm_helpBrowser = nullptr;
 }
+#endif
 
 void MainWindow::enterWhatsThis() { QWhatsThis::enterWhatsThisMode(); }
 
@@ -1451,9 +1457,11 @@ void MainWindow::closeEvent(QCloseEvent *event) {
     }
     sm_NumMainWindows--;
     if (sm_NumMainWindows == 0) {
+#ifdef WITH_HELPBROWSER
         if (sm_helpBrowser) {
             sm_helpBrowser->close();
         }
+#endif
     }
 
     if (sm_NumMainWindows == 0) {
