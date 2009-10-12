--- ./src/calibre/gui2/dialogs/metadata_single.py.orig	2009-10-11 19:16:07.000000000 +0400
+++ ./src/calibre/gui2/dialogs/metadata_single.py	2009-10-11 19:16:34.000000000 +0400
@@ -24,7 +24,7 @@
 from calibre.ebooks import BOOK_EXTENSIONS
 from calibre.ebooks.metadata import authors_to_sort_string, string_to_authors, authors_to_string
 from calibre.ebooks.metadata.library_thing import cover_from_isbn
-from calibre import islinux
+from calibre import islinux, isfreebsd
 from calibre.ebooks.metadata.meta import get_metadata
 from calibre.utils.config import prefs
 from calibre.customize.ui import run_plugins_on_import
@@ -382,8 +382,8 @@
         height_of_rest = self.frameGeometry().height() - self.cover.height()
         width_of_rest  = self.frameGeometry().width() - self.cover.width()
         ag = QCoreApplication.instance().desktop().availableGeometry(self)
-        self.cover.MAX_HEIGHT = ag.height()-(25 if islinux else 0)-height_of_rest
-        self.cover.MAX_WIDTH = ag.width()-(25 if islinux else 0)-width_of_rest
+        self.cover.MAX_HEIGHT = ag.height()-(25 if (islinux or isfreebsd) else 0)-height_of_rest
+        self.cover.MAX_WIDTH = ag.width()-(25 if (islinux or isfreebsd) else 0)-width_of_rest
         if cover:
             pm = QPixmap()
             pm.loadFromData(cover)
