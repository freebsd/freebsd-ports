--- tests/src/playlist_test.cpp.orig	2020-04-27 23:42:17 UTC
+++ tests/src/playlist_test.cpp
@@ -53,15 +53,15 @@ class PlaylistTest : public ::testing::Test {
     Song metadata;
     metadata.Init(title, artist, album, length);
 
-    //MockPlaylistItem* ret = new MockPlaylistItem;
+    MockPlaylistItem *ret = new MockPlaylistItem;
     //EXPECT_CALL(*ret, Metadata()).WillRepeatedly(Return(metadata));
 
-    //return ret;
+    return ret;
     return nullptr;
   }
 
-  std::shared_ptr<PlaylistItem> MakeMockItemP(const QString& title, const QString& artist = QString(), const QString& album = QString(), int length = 123) const {
-    return std::shared_ptr<PlaylistItem>(MakeMockItem(title, artist, album, length));
+  PlaylistItemPtr MakeMockItemP(const QString& title, const QString& artist = QString(), const QString& album = QString(), int length = 123) const {
+    return PlaylistItemPtr(MakeMockItem(title, artist, album, length));
   }
 
   Playlist playlist_;
@@ -76,7 +76,7 @@ TEST_F(PlaylistTest, Basic) {
 TEST_F(PlaylistTest, InsertItems) {
 
   MockPlaylistItem* item = MakeMockItem("Title", "Artist", "Album", 123);
-  std::shared_ptr<PlaylistItem> item_ptr(item);
+  PlaylistItemPtr item_ptr(item);
 
   // Insert the item
   EXPECT_EQ(0, playlist_.rowCount(QModelIndex()));
