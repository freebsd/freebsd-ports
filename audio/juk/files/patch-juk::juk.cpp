--- juk/juk.cpp.orig	Tue Feb 18 05:29:20 2003
+++ juk/juk.cpp	Mon Mar  3 12:24:34 2003
@@ -52,6 +52,7 @@
     readSettings();
     setupLayout();
     setupActions();
+    playlistChanged();
     readConfig();
     setupPlayer();
     setupSystemTray();
@@ -84,8 +85,6 @@
 
     connect(splitter, SIGNAL(selectedPlaylistCountChanged(int)), statusLabel, SLOT(setPlaylistCount(int)));
     connect(statusLabel, SIGNAL(jumpButtonClicked()), splitter, SLOT(selectPlaying()));
-
-    updatePlaylistInfo();
 
     splitter->setFocus();
 
