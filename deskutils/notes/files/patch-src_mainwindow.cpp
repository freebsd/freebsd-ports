--- src/mainwindow.cpp.orig	2022-09-07 07:59:26 UTC
+++ src/mainwindow.cpp
@@ -8,7 +8,6 @@
 #include "ui_mainwindow.h"
 #include "notelistdelegate.h"
 #include "qxtglobalshortcut.h"
-#include "updaterwindow.h"
 #include "treeviewlogic.h"
 #include "listviewlogic.h"
 #include "noteeditorlogic.h"
@@ -79,7 +78,6 @@ MainWindow::MainWindow(QWidget *parent) :
     m_isTemp(false),
     m_isListViewScrollBarHidden(true),
     m_isOperationRunning(false),
-    m_dontShowUpdateWindow(false),
     m_alwaysStayOnTop(false),
     m_useNativeWindowFrame(false),
     m_listOfSerifFonts({QStringLiteral("Trykker"), QStringLiteral("PT Serif"), QStringLiteral("Mate")}),
@@ -123,7 +121,6 @@ MainWindow::MainWindow(QWidget *parent) :
     setupTextEdit();
     restoreStates();
     setupSignalsSlots();
-    autoCheckForUpdates();
 
     QTimer::singleShot(200,this, SLOT(InitData()));
 }
@@ -587,7 +584,6 @@ void MainWindow::setupSignalsSlots()
  */
 void MainWindow::setupSignalsSlots()
 {
-    connect(&m_updater, &UpdaterWindow::dontShowUpdateWindowChanged, this, [=](bool state){m_dontShowUpdateWindow = state;});
     // Style Editor Window
     connect(&m_styleEditorWindow, &StyleEditorWindow::changeFontType, this, [=](FontTypeface fontType){changeEditorFontTypeFromStyleButtons(fontType);});
     connect(&m_styleEditorWindow, &StyleEditorWindow::changeFontSize, this, [=](FontSizeAction fontSizeAction){changeEditorFontSizeFromStyleButtons(fontSizeAction);});
@@ -728,6 +724,7 @@ void MainWindow::setupSignalsSlots()
             m_dbManager, &DBManager::onChangeDatabasePathRequested, Qt::QueuedConnection);
 }
 
+#if 0
 /*!
  * \brief MainWindow::autoCheckForUpdates
  * Checks for updates, if an update is found, then the updater dialog will show
@@ -739,6 +736,7 @@ void MainWindow::autoCheckForUpdates()
     m_updater.setShowWindowDisable(m_dontShowUpdateWindow);
     m_updater.checkForUpdates(false);
 }
+#endif
 
 void MainWindow::setSearchEditStyleSheet(bool isFocused = false)
 {
@@ -988,8 +986,10 @@ void MainWindow::initializeSettingsDatabase()
     if(m_settingsDatabase->value(QStringLiteral("version"), "NULL") == "NULL")
         m_settingsDatabase->setValue(QStringLiteral("version"), qApp->applicationVersion());
 
+#if 0
     if(m_settingsDatabase->value(QStringLiteral("dontShowUpdateWindow"), "NULL") == "NULL")
         m_settingsDatabase->setValue(QStringLiteral("dontShowUpdateWindow"), m_dontShowUpdateWindow);
+#endif
 
     if(m_settingsDatabase->value(QStringLiteral("windowGeometry"), "NULL") == "NULL"){
         int initWidth = 870;
@@ -1169,8 +1169,10 @@ void MainWindow::restoreStates()
     //    }
 #endif
 
+#if 0
     if(m_settingsDatabase->value(QStringLiteral("dontShowUpdateWindow"), "NULL") != "NULL")
         m_dontShowUpdateWindow = m_settingsDatabase->value(QStringLiteral("dontShowUpdateWindow")).toBool();
+#endif
 
     m_splitter->setCollapsible(0, true);
     m_splitter->resize(width() - m_layoutMargin, height() - m_layoutMargin);
@@ -1448,9 +1450,11 @@ void MainWindow::onDotsButtonClicked()
         }
     });
 
+#if 0
     // Check for update action
     QAction* checkForUpdatesAction = mainMenu.addAction(tr("Check For Updates"));
     connect (checkForUpdatesAction, &QAction::triggered, this, &MainWindow::checkForUpdates);
+#endif
 
     // Autostart
     QAction* autostartAction = mainMenu.addAction(tr("Start automatically"));
@@ -1937,6 +1941,7 @@ void MainWindow::QuitApplication()
     MainWindow::close();
 }
 
+#if 0
 /*!
  * \brief MainWindow::checkForUpdates
  * Called when the "Check for Updates" menu item is clicked, this function
@@ -1948,6 +1953,7 @@ void MainWindow::checkForUpdates(const bool clicked)
     Q_UNUSED (clicked)
     m_updater.checkForUpdates(true);
 }
+#endif
 
 /*!
  * \brief MainWindow::importNotesFile
@@ -2282,7 +2288,6 @@ void MainWindow::closeEvent(QCloseEvent* event)
 
     m_noteEditorLogic->saveNoteToDB();
 
-    m_settingsDatabase->setValue(QStringLiteral("dontShowUpdateWindow"), m_dontShowUpdateWindow);
     m_settingsDatabase->setValue(QStringLiteral("splitterSizes"), m_splitter->saveState());
 
     QString currentFontTypefaceString;
@@ -3174,6 +3179,7 @@ bool MainWindow::eventFilter(QObject *object, QEvent *
 
         //        alignTextEditText();
     }
+#if 0
     case QEvent::Show:
         if(object == &m_updater){
 
@@ -3187,6 +3193,7 @@ bool MainWindow::eventFilter(QObject *object, QEvent *
             m_updater.setGeometry(QRect(x, y, rect.width(), rect.height()));
         }
         break;
+#endif
     case QEvent::MouseButtonPress:
     case QEvent::MouseButtonDblClick:
         // Only allow double click (maximise/minimise) or dragging (move)
