--- tests/tools.cpp.orig	2025-02-14 14:36:02 UTC
+++ tests/tools.cpp
@@ -693,7 +693,7 @@ QString Mediainfo::tagToJsonPath(const QString &tag) c
 {
     if (mFileExt == "wv") {
         // clang-format off
-        if (tag == "AlbumPerformer") return "extra/ALBUM_ARTIST";
+        if (tag == "extra/ALBUM_ARTIST") return "Album_Performer";
         // clang-format on
     }
 
