--- ./src/app/cli/kid3cli.cpp.orig	2013-11-29 06:55:07.000000000 +0000
+++ ./src/app/cli/kid3cli.cpp	2013-12-02 14:35:10.196660693 +0000
@@ -276,7 +276,10 @@
          << new CopyCommand(this)
          << new PasteCommand(this)
          << new RemoveCommand(this)
-         << new PlayCommand(this);
+#if defined HAVE_PHONON || QT_VERSION >= 0x050000
+         << new PlayCommand(this)
+#endif
+         ;
   connect(m_app, SIGNAL(fileSelectionUpdateRequested()),
           this, SLOT(updateSelectedFiles()));
   connect(m_app, SIGNAL(selectedFilesUpdated()),
