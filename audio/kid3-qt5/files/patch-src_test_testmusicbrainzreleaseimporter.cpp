Fix test to reflect the current data in the MusicBrainz database.

--- src/test/testmusicbrainzreleaseimporter.cpp.orig	2019-08-23 09:52:05 UTC
+++ src/test/testmusicbrainzreleaseimporter.cpp
@@ -38,7 +38,7 @@ void TestMusicBrainzReleaseImporter::testQueryAlbums()
 {
   queryAlbums(QLatin1String("Wizard"), QLatin1String("Odin"));
   AlbumListModel* albumModel = m_importer->getAlbumListModel();
-  QCOMPARE(albumModel->rowCount(), 3);
+  QCOMPARE(albumModel->rowCount(), 4);
   QString text, category, id;
   albumModel->getItem(0, text, category, id);
   QCOMPARE(text, QString(QLatin1String("Wizard - Odin")));
@@ -53,9 +53,9 @@ void TestMusicBrainzReleaseImporter::testQueryTracks()
   QStringList titles;
   titles << QLatin1String("The Prophecy") << QLatin1String("Betrayer")
          << QLatin1String("Dead Hope") << QLatin1String("Dark God")
-         << QLatin1String("Loki's Punishment")
+         << QString::fromUtf8("Loki\u2019s Punishment")
          << QLatin1String("Beginning of the End")
-         << QLatin1String("Thor's Hammer")
+         << QString::fromUtf8("Thor\u2019s Hammer")
          << QLatin1String("Hall of Odin") << QLatin1String("The Powergod")
          << QLatin1String("March of the Einheriers")
          << QLatin1String("End of All");
@@ -65,7 +65,7 @@ void TestMusicBrainzReleaseImporter::testQueryTracks()
           << QLatin1String("5:08") << QLatin1String("4:01")
           << QLatin1String("5:01") << QLatin1String("5:06")
           << QLatin1String("5:21") << QLatin1String("5:40")
-          << QLatin1String("3:53");
+          << QLatin1String("3:55");
   QCOMPARE(m_trackDataModel->rowCount(), 11);
   for (int row = 0; row < 11; ++row) {
     QCOMPARE(m_trackDataModel->index(row, 0).data().toString(),
