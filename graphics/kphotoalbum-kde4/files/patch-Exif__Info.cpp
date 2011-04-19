--- ./Exif/Info.cpp.orig	2010-02-11 22:44:01.000000000 +0100
+++ ./Exif/Info.cpp	2011-04-19 10:47:27.975620628 +0200
@@ -106,6 +106,28 @@
         return res;
 
     QList<const Exiv2::TagInfo*> tags;
+    std::ostringstream s;
+
+#if (EXIV2_TEST_VERSION(0,21,0))
+    const Exiv2::GroupInfo* gi = Exiv2::ExifTags::groupList();
+    while (gi->tagList_ != 0) {
+	    Exiv2::TagListFct tl     = gi->tagList_;
+	    const Exiv2::TagInfo* ti = tl();
+
+	    while (ti->tag_ != 0xFFFF) {
+		    tags << ti;
+		    ++ti;
+	    }
+        ++gi;
+    }
+
+    for (QList<const Exiv2::TagInfo*>::iterator it = tags.begin(); it != tags.end(); ++it) {
+        while ( (*it)->tag_ != 0xffff ) {
+            res.insert(QString::fromLatin1(Exiv2::ExifKey(**it).key().c_str()));
+            ++(*it);
+        }
+    }
+#else
     tags <<
         Exiv2::ExifTags::ifdTagList() <<
         Exiv2::ExifTags::exifTagList() <<
@@ -121,7 +143,6 @@
     // Now the ugly part -- exiv2 doesn't have any way to get a list of
     // MakerNote tags in a reasonable form, so we have to parse it from strings
 
-    std::ostringstream s;
     for ( Exiv2::IfdId kind = Exiv2::canonIfdId; kind < Exiv2::lastIfdId;
             kind = static_cast<Exiv2::IfdId>( kind + 1 ) ) {
 #if EXIV2_TEST_VERSION(0,17,0)
@@ -130,6 +151,7 @@
         Exiv2::ExifTags::makerTaglist( s, kind );
 #endif
     }
+#endif
 
     // IPTC tags use yet another format...
     Exiv2::IptcDataSets::dataSetList( s );
