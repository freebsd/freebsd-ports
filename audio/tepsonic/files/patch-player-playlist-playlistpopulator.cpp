--- player/playlist/playlistpopulator.cpp.orig	2011-04-02 21:48:45.000000000 +0800
+++ player/playlist/playlistpopulator.cpp	2011-04-02 21:49:04.000000000 +0800
@@ -31,9 +31,9 @@
 #include <QSqlDriver>
 #include <QSqlQuery>
 
-#include <taglib/taglib.h>
-#include <taglib/fileref.h>
-#include <taglib/tag.h>
+#include <taglib.h>
+#include <fileref.h>
+#include <tag.h>
 
 PlaylistPopulator::PlaylistPopulator()
 {
