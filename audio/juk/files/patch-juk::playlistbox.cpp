--- juk/playlistbox.cpp.orig	Mon Feb 17 04:03:17 2003
+++ juk/playlistbox.cpp	Mon Mar  3 12:24:34 2003
@@ -129,7 +129,7 @@
 
     bool ok;
 
-    QString name = QInputDialog::getText(i18n("Rename..."), i18n("Please enter a name for this playlist:"),
+    QString name = QInputDialog::getText(i18n("Rename"), i18n("Please enter a name for this playlist:"),
 					 QLineEdit::Normal, item->text(), &ok);
     if(ok) {
 	item->setText(name);
@@ -158,7 +158,7 @@
 
 	// If this text is changed, please also change it in PlaylistSplitter::createPlaylist().
 
-	QString name = QInputDialog::getText(i18n("New Playlist..."), i18n("Please enter a name for the new playlist:"),
+	QString name = QInputDialog::getText(i18n("New Playlist"), i18n("Please enter a name for the new playlist:"),
 					     QLineEdit::Normal, splitter->uniquePlaylistName(item->text(), true), &ok);
 	if(ok) {
 	    Playlist *p = splitter->createPlaylist(name);
