Squash startup warnings for KF5 app.

Shortcut for action  "open_directory" "O&pen Directory..." set with QAction::setShortcut()! Use KActionCollection::setDefaultShortcut(s) instead.
Shortcut for action  "filelist_rename" "&Rename" set with QAction::setShortcut()! Use KActionCollection::setDefaultShortcut(s) instead.
Shortcut for action  "filelist_delete" "&Move to Trash" set with QAction::setShortcut()! Use KActionCollection::setDefaultShortcut(s) instead.

--- src/app/kde/kdemainwindow.cpp.orig	2018-03-18 20:56:24 UTC
+++ src/app/kde/kdemainwindow.cpp
@@ -162,7 +162,12 @@ void KdeMainWindow::initActions()
   action = new KAction(KIcon(QLatin1String("document-open")),
                        tr("O&pen Directory..."), this);
   action->setStatusTip(tr("Opens a directory"));
+#if QT_VERSION >= 0x050000
+  collection->setDefaultShortcut(action,
+                          QKeySequence(Qt::CTRL + Qt::Key_D));
+#else
   action->setShortcut(KShortcut(QLatin1String("Ctrl+D")));
+#endif
   collection->addAction(QLatin1String("open_directory"), action);
   connect(action, SIGNAL(triggered()), impl(), SLOT(slotFileOpenDirectory()));
   action = new KAction(KIcon(QLatin1String("document-import")),
@@ -359,13 +364,23 @@ void KdeMainWindow::initActions()
   collection->addAction(QLatin1String("filelist_focus"), action);
   connect(action, SIGNAL(triggered()), form(), SLOT(setFocusFileList()));
   action = new KAction(tr("&Rename"), this);
+#if QT_VERSION >= 0x050000
+  collection->setDefaultShortcut(action,
+                          QKeySequence(Qt::Key_F2));
+#else
   action->setShortcut(QKeySequence(Qt::Key_F2));
+#endif
   action->setShortcutContext(Qt::WidgetShortcut);
   connect(action, SIGNAL(triggered()), impl(), SLOT(renameFile()));
   collection->addAction(QLatin1String("filelist_rename"), action);
   form()->getFileList()->setRenameAction(action);
   action = new KAction(tr("&Move to Trash"), this);
+#if QT_VERSION >= 0x050000
+  collection->setDefaultShortcut(action,
+                          QKeySequence::Delete);
+#else
   action->setShortcut(QKeySequence::Delete);
+#endif
   action->setShortcutContext(Qt::WidgetShortcut);
   connect(action, SIGNAL(triggered()), impl(), SLOT(deleteFile()));
   collection->addAction(QLatin1String("filelist_delete"), action);
