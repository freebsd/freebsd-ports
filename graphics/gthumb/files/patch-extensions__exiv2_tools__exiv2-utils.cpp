--- ./extensions/exiv2_tools/exiv2-utils.cpp.orig	2010-09-15 21:07:15.000000000 +0200
+++ ./extensions/exiv2_tools/exiv2-utils.cpp	2011-04-11 15:39:59.491373470 +0200
@@ -497,19 +497,19 @@
 static const char *
 get_exif_default_category (const Exiv2::Exifdatum &md)
 {
+#if EXIV2_TEST_VERSION(0, 21, 0)
+	if (Exiv2::ExifTags::isMakerGroup(md.groupName()))
+#else
 	if (Exiv2::ExifTags::isMakerIfd(md.ifdId()))
+#endif
 		return "Exif::MakerNotes";
 
-	switch (md.ifdId()) {
-	case Exiv2::ifd1Id:
+	if (md.groupName().compare("Thumbnail") == 0)
 		return "Exif::Thumbnail";
-	case Exiv2::gpsIfdId:
+	else if (md.groupName().compare("GPSInfo") == 0)
 		return "Exif::GPS";
-	case Exiv2::iopIfdId:
+	else if (md.groupName().compare("Iop") == 0)
 		return "Exif::Versions";
-	default:
-		break;
-	}
 
 	return "Exif::Other";
 }
@@ -531,7 +531,11 @@
 			stringstream description;
 			if (! md->tagLabel().empty())
 				description << md->tagLabel();
-			else if (md->ifdId () > Exiv2::ifd1Id)
+#if EXIV2_TEST_VERSION(0, 21, 0)
+			else if (Exiv2::ExifTags::isMakerGroup(md->groupName()))
+#else
+			else if (Exiv2::ExifTags::isMakerIfd(md->ifdId()))
+#endif
 				// Must be a MakerNote - include group name
 				description << md->groupName() << "." << md->tagName();
 			else
