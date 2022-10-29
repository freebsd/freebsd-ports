--- src/mainwindow.h.orig	2022-09-07 07:59:26 UTC
+++ src/mainwindow.h
@@ -29,7 +29,6 @@
 #include "notelistmodel.h"
 #include "notelistview.h"
 #include "nodetreemodel.h"
-#include "updaterwindow.h"
 #include "styleeditorwindow.h"
 #include "dbmanager.h"
 #include "customDocument.h"
@@ -151,7 +150,6 @@ public slots: (private)
     DBManager* m_dbManager;
     QThread* m_dbThread;
     SpliterStyle* m_spliterStyle;
-    UpdaterWindow m_updater;
     StyleEditorWindow m_styleEditorWindow;
     AboutWindow m_aboutWindow;
     StretchSide m_stretchSide;
@@ -170,7 +168,6 @@ public slots: (private)
     bool m_isTemp;
     bool m_isListViewScrollBarHidden;
     bool m_isOperationRunning;
-    bool m_dontShowUpdateWindow;
     bool m_alwaysStayOnTop;
     bool m_useNativeWindowFrame;
 
@@ -262,7 +259,6 @@ private slots:
     void maximizeWindow();
     void minimizeWindow();
     void QuitApplication();
-    void checkForUpdates (const bool clicked);
     void collapseNoteList();
     void expandNoteList();
     void toggleNoteList();
