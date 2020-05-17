--- tests/src/organiseformat_test.cpp.orig	2019-06-29 18:18:34 UTC
+++ tests/src/organiseformat_test.cpp
@@ -59,6 +59,7 @@ TEST_F(OrganiseFormatTest, BasicReplace) {
   format_.set_format("%album %albumartist %artist %bitrate %comment %composer %performer %grouping %disc %genre %length %samplerate %bitdepth %title %track %year");
 
   ASSERT_TRUE(format_.IsValid());
+
   EXPECT_EQ("album_albumartist_artist_123_comment_composer_performer_grouping_789_genre_987_654_32_title_321_2010", format_.GetFilenameForSong(song_));
 
 }
@@ -135,11 +136,12 @@ TEST_F(OrganiseFormatTest, ReplaceNonAscii) {
 
   format_.set_remove_non_ascii(false);
   EXPECT_EQ(QString::fromUtf8("Röyksopp"), format_.GetFilenameForSong(song_));
+
   format_.set_remove_non_ascii(true);
   EXPECT_EQ("Royksopp", format_.GetFilenameForSong(song_));
 
   song_.set_artist(QString::fromUtf8("Владимир Высоцкий"));
-  EXPECT_EQ("_________________", format_.GetFilenameForSong(song_));
+  EXPECT_EQ("????????_????????", format_.GetFilenameForSong(song_));
 
 }
 
