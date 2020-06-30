Squash startup warnings for KF5 app.

Shortcut for action  "open_directory" "O&pen Directory..." set with QAction::setShortcut()! Use KActionCollection::setDefaultShortcut(s) instead.
Shortcut for action  "reload" "Re&load" set with QAction::setShortcut()! Use KActionCollection::setDefaultShortcut(s) instead.
Shortcut for action  "filelist_rename" "&Rename" set with QAction::setShortcut()! Use KActionCollection::setDefaultShortcut(s) instead.
Shortcut for action  "filelist_delete" "&Move to Trash" set with QAction::setShortcut()! Use KActionCollection::setDefaultShortcut(s) instead.

--- src/app/kde/kdemainwindow.cpp.orig	2020-05-09 12:12:37 UTC
+++ src/app/kde/kdemainwindow.cpp
@@ -189,7 +189,7 @@ void KdeMainWindow::initActions()
   action = new QAction(QIcon::fromTheme(QLatin1String("document-open")),
                        tr("O&pen Folder..."), this);
   action->setStatusTip(tr("Opens a folder"));
-  action->setShortcut(QKeySequence(QLatin1String("Ctrl+D")));
+  collection->setDefaultShortcut(action, QKeySequence(Qt::CTRL + Qt::Key_D));
   collection->addAction(QLatin1String("open_directory"), action);
   connect(action, &QAction::triggered,
           impl(), &BaseMainWindowImpl::slotFileOpenDirectory);
@@ -197,7 +197,7 @@ void KdeMainWindow::initActions()
   action = new QAction(QIcon::fromTheme(QLatin1String("view-refresh")),
                        tr("Re&load"), this);
   action->setStatusTip(tr("Reload folder"));
-  action->setShortcut(QKeySequence::Refresh);
+  collection->setDefaultShortcut(action, QKeySequence::Refresh);
   collection->addAction(QLatin1String("reload"), action);
   connect(action, &QAction::triggered,
           impl(), &BaseMainWindowImpl::slotFileReload);
@@ -415,13 +415,13 @@ void KdeMainWindow::initActions()
   collection->addAction(QLatin1String("filelist_focus"), action);
   connect(action, &QAction::triggered, form(), &Kid3Form::setFocusFileList);
   action = new QAction(tr("&Rename"), this);
-  action->setShortcut(QKeySequence(Qt::Key_F2));
+  collection->setDefaultShortcut(action, QKeySequence(Qt::Key_F2));
   action->setShortcutContext(Qt::WidgetShortcut);
   connect(action, &QAction::triggered, impl(), &BaseMainWindowImpl::renameFile);
   collection->addAction(QLatin1String("filelist_rename"), action);
   form()->getFileList()->setRenameAction(action);
   action = new QAction(tr("&Move to Trash"), this);
-  action->setShortcut(QKeySequence::Delete);
+  collection->setDefaultShortcut(action, QKeySequence::Delete);
   action->setShortcutContext(Qt::WidgetShortcut);
   connect(action, &QAction::triggered, impl(), &BaseMainWindowImpl::deleteFile);
   collection->addAction(QLatin1String("filelist_delete"), action);
