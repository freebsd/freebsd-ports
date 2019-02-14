Fix import of album title from Discogs. (fixed upstream: b3bd70)

--- src/plugins/discogsimport/discogsimporter.cpp.orig	2018-12-21 05:40:14 UTC
+++ src/plugins/discogsimport/discogsimporter.cpp
@@ -265,7 +265,7 @@ void DiscogsImporter::parseFindResults(const QByteArra
 void DiscogsImporter::parseAlbumResults(const QByteArray& albumStr)
 {
   QRegExp nlSpaceRe(QLatin1String("[\r\n]+\\s*"));
-  QRegExp atDiscogsRe(QLatin1String("\\s*\\([^)]+\\) at Discogs\n?$"));
+  QRegExp atDiscogsRe(QLatin1String("\\s*\\([^)]+\\) (?:at|\\|) Discogs\n?$"));
   QString str = QString::fromUtf8(albumStr);
 
   FrameCollection framesHdr;
