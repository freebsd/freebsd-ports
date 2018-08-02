Fix import of track duration from Discogs.

--- src/plugins/discogsimport/discogsimporter.cpp.orig	2018-04-18 18:01:00 UTC
+++ src/plugins/discogsimport/discogsimporter.cpp
@@ -526,8 +526,8 @@ void DiscogsImporter::parseAlbumResults(const QByteArr
       QRegExp titleRe(QLatin1String(
         "class=\"tracklist_track_title\"[^>]*>([^<]+)<"));
       QRegExp durationRe(QLatin1String(
-        "<td [^>]*class=\"tracklist_track_duration\"[^>]*>(?:<meta[^>]*>)?"
-        "(?:<span>)?(\\d+):(\\d+)</"));
+        "<td [^>]*class=\"tracklist_track_duration\">"
+        "(?:<meta[^>]*>)(?:\\s+<span>)(\\d+):(\\d+)</"));
       QRegExp indexRe(QLatin1String("<td class=\"track_index\">([^<]+)$"));
       QRegExp rowEndRe(QLatin1String("</td>[\\s\\r\\n]*</tr>"));
       ImportTrackDataVector::iterator it = trackDataVector.begin();
