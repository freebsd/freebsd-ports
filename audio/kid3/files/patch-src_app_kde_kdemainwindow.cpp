Squash startup warnings for KF5 app.

Shortcut for action  "open_directory" "O&pen Directory..." set with QAction::setShortcut()! Use KActionCollection::setDefaultShortcut(s) instead.
Shortcut for action  "reload" "Re&load" set with QAction::setShortcut()! Use KActionCollection::setDefaultShortcut(s) instead.
Shortcut for action  "filelist_rename" "&Rename" set with QAction::setShortcut()! Use KActionCollection::setDefaultShortcut(s) instead.
Shortcut for action  "filelist_delete" "&Move to Trash" set with QAction::setShortcut()! Use KActionCollection::setDefaultShortcut(s) instead.

--- src/app/kde/kdemainwindow.cpp.orig	2025-07-24 02:28:50 UTC
+++ src/app/kde/kdemainwindow.cpp
@@ -190,7 +190,7 @@ void KdeMainWindow::initActions()
   action = new QAction(QIcon::fromTheme(QLatin1String("document-open")),
                        tr("O&pen Folder..."), this);
   action->setStatusTip(tr("Opens a folder"));
-  action->setShortcut(QKeySequence(QLatin1String("Ctrl+D")));
+  collection->setDefaultShortcut(action, QKeySequence(Qt::CTRL + Qt::Key_D));
   collection->addAction(QLatin1String("open_directory"), action);
   connect(action, &QAction::triggered,
           impl(), &BaseMainWindowImpl::slotFileOpenDirectory);
@@ -203,7 +203,7 @@ void KdeMainWindow::initActions()
   // Avoid this by assigning Qt::Key_F5 instead of QKeySequence::Refresh.
   // The section "Standard Shortcuts" in the QKeySequence documentation lists
   // F5 as a key for "Refresh" on all platforms.
-  action->setShortcut(Qt::Key_F5);
+  collection->setDefaultShortcut(action, QKeySequence(Qt::Key_F5));
   collection->addAction(QLatin1String("reload"), action);
   connect(action, &QAction::triggered,
           impl(), &BaseMainWindowImpl::slotFileReload);
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
