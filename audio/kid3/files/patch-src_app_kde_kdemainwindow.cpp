Squash startup warnings for KF6 app.

Shortcut for action  "filelist_rename" "&Rename" set with QAction::setShortcut()! Use KActionCollection::setDefaultShortcut(s) instead.
Shortcut for action  "filelist_delete" "&Move to Trash" set with QAction::setShortcut()! Use KActionCollection::setDefaultShortcut(s) instead.

--- src/app/kde/kdemainwindow.cpp.orig	2026-10-08 14:44:20 UTC
+++ src/app/kde/kdemainwindow.cpp
@@ -424,7 +424,7 @@ void KdeMainWindow::initActions()
   collection->addAction(QLatin1String("filelist_focus"), action);
   connect(action, &QAction::triggered, form(), &Kid3Form::setFocusFileList);
   action = new QAction(tr("&Rename"), this);
-  action->setShortcut(QKeySequence(Qt::Key_F2));
+  collection->setDefaultShortcut(action, QKeySequence(Qt::Key_F2));
   action->setShortcutContext(Qt::WidgetShortcut);
   connect(action, &QAction::triggered, impl(), &BaseMainWindowImpl::renameFile);
   // This action is not made configurable because its shortcut F2 conflicts
@@ -433,7 +433,7 @@ void KdeMainWindow::initActions()
   // collection->addAction(QLatin1String("filelist_rename"), action);
   form()->getFileList()->setRenameAction(action);
   action = new QAction(tr("&Move to Trash"), this);
-  action->setShortcut(QKeySequence::Delete);
+  collection->setDefaultShortcut(action, QKeySequence::Delete);
   action->setShortcutContext(Qt::WidgetShortcut);
   connect(action, &QAction::triggered, impl(), &BaseMainWindowImpl::deleteFile);
   // collection->addAction(QLatin1String("filelist_delete"), action);
