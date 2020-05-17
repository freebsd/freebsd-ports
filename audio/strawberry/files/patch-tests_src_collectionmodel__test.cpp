--- tests/src/collectionmodel_test.cpp.orig	2020-04-27 23:42:17 UTC
+++ tests/src/collectionmodel_test.cpp
@@ -75,6 +75,8 @@ class CollectionModelTest : public ::testing::Test {
   Song AddSong(const QString& title, const QString& artist, const QString& album, int length) {
     Song song;
     song.Init(title, artist, album, length);
+    song.set_mtime(0);
+    song.set_ctime(0);
     return AddSong(song);
   }
 
@@ -111,6 +113,8 @@ TEST_F(CollectionModelTest, CompilationAlbums) {
   Song song;
   song.Init("Title", "Artist", "Album", 123);
   song.set_compilation(true);
+  song.set_mtime(0);
+  song.set_ctime(0);
 
   AddSong(song);
   model_->Init(false);
@@ -200,6 +204,8 @@ TEST_F(CollectionModelTest, VariousArtistSongs) {
     QString n = QString::number(i+1);
     Song song;
     song.Init("Title " + n, "Artist " + n, "Album", 0);
+    song.set_mtime(0);
+    song.set_ctime(0);
     songs << song;
   }
 
