cmID and xid atoms only supported in mp4v2 >= 2.0.0

--- src/plugins/mp4v2metadata/m4afile.cpp.orig	2018-04-18 18:01:00 UTC
+++ src/plugins/mp4v2metadata/m4afile.cpp
@@ -136,6 +136,8 @@ static const struct {
   { "geID", Frame::FT_Other },
   { "purl", Frame::FT_Other },
   { "egid", Frame::FT_Other },
+#endif
+#if MPEG4IP_MAJOR_MINOR_VERSION >= 0x0200
   { "cmID", Frame::FT_Other },
   { "xid ", Frame::FT_Other },
 #endif
@@ -346,8 +348,11 @@ static QByteArray getValueByteArray(const char* name,
 #if MPEG4IP_MAJOR_MINOR_VERSION >= 0x0109
   } else if (std::strcmp(name, "tvsn") == 0 || std::strcmp(name, "tves") == 0 ||
              std::strcmp(name, "sfID") == 0 || std::strcmp(name, "cnID") == 0 ||
-             std::strcmp(name, "atID") == 0 || std::strcmp(name, "geID") == 0 ||
-             std::strcmp(name, "cmID") == 0) {
+             std::strcmp(name, "atID") == 0 || std::strcmp(name, "geID") == 0
+#if MPEG4IP_MAJOR_MINOR_VERSION >= 0x0200
+             || std::strcmp(name, "cmID") == 0
+#endif
+            ) {
     if (size >= 4) {
       uint val = value[3] + (value[2] << 8) +
         (value[1] << 16) + (value[0] << 24);
@@ -712,11 +717,13 @@ bool M4aFile::writeTags(bool force, bool* renamed, boo
           } else if (name == QLatin1String("geID")) {
             uint32_t val = str.toULong();
             MP4TagsSetGenreID(tags, &val);
+#if MPEG4IP_MAJOR_MINOR_VERSION >= 0x0200
           } else if (name == QLatin1String("cmID")) {
             uint32_t val = str.toULong();
             MP4TagsSetComposerID(tags, &val);
           } else if (name == QLatin1String("xid ")) {
             MP4TagsSetXID(tags, str);
+#endif
           } else {
             MP4ItmfItem* item;
             if (name.length() == 4 &&
@@ -1306,7 +1313,10 @@ QStringList M4aFile::getFrameIds(Frame::TagNumber tagN
     QLatin1String("plID") << QLatin1String("purd") << QLatin1String("rtng") << QLatin1String("sfID") <<
     QLatin1String("sosn") << QLatin1String("stik") << QLatin1String("tven") <<
     QLatin1String("tves") << QLatin1String("tvnn") << QLatin1String("tvsh") << QLatin1String("tvsn") <<
-    QLatin1String("purl") << QLatin1String("egid") << QLatin1String("cmID") << QLatin1String("xid ");
+    QLatin1String("purl") << QLatin1String("egid");
+#endif
+#if MPEG4IP_MAJOR_MINOR_VERSION >= 0x0200
+  lst << QLatin1String("cmID") << QLatin1String("xid ");
 #endif
   return lst;
 }
