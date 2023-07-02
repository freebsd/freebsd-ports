--- src/exiv2.cc.orig	2022-08-12 09:36:37 UTC
+++ src/exiv2.cc
@@ -52,6 +52,11 @@
 #define EXV_PACKAGE "exiv2"
 #endif
 
+#if EXIV2_TEST_VERSION(0,28,0)
+#define AnyError Error
+#define AutoPtr UniquePtr
+#endif 
+
 extern "C" {
 #include <glib.h>
 
@@ -176,7 +181,7 @@ struct _ExifDataOriginal : public _ExifData (public)
 	{
 		cp_data_ = NULL;
 		cp_length_ = 0;
-		image_ = image;
+		image_ = std::move(image);
 		valid_ = TRUE;
 	}
 
@@ -364,7 +369,7 @@ struct _ExifDataProcessed : public _ExifData (public)
 			Exiv2::Image *image = imageData_->image();
 
 #ifdef HAVE_EXIV2_ERROR_CODE
-			if (!image) throw Exiv2::Error(Exiv2::kerInputDataReadFailed);
+			if (!image) throw Exiv2::Error(Exiv2::ErrorCode::kerInputDataReadFailed);
 #else
 			if (!image) throw Exiv2::Error(21);
 #endif
@@ -388,7 +393,7 @@ struct _ExifDataProcessed : public _ExifData (public)
 			sidecar->writeMetadata();
 #else
 #ifdef HAVE_EXIV2_ERROR_CODE
-			throw Exiv2::Error(Exiv2::kerNotAnImage, "xmp");
+			throw Exiv2::Error(Exiv2::ErrorCode::kerNotAnImage, "xmp");
 #else
 			throw Exiv2::Error(3, "xmp");
 #endif
@@ -840,7 +845,7 @@ gint exif_item_get_integer(ExifItem *item, gint *value
 {
 	try {
 		if (!item || exif_item_get_elements(item) == 0) return 0;
-		*value = ((Exiv2::Metadatum *)item)->toLong();
+		*value = ((Exiv2::Metadatum *)item)->toInt64();
 		return 1;
 	}
 	catch (Exiv2::AnyError& e) {
@@ -1224,11 +1229,12 @@ guchar *exif_get_preview(ExifData *exif, guint *data_l
 
 			Exiv2::PreviewImage image = pm.getPreviewImage(*pos);
 
+			// https://github.com/BestImageViewer/geeqie/issues/1090
 			Exiv2::DataBuf buf = image.copy();
-			std::pair<Exiv2::byte*, long> p = buf.release();
-
-			*data_len = p.second;
-			return p.first;
+			*data_len = buf.size();
+			auto b = buf.data();
+			buf.reset();
+			return b;
 			}
 		return NULL;
 	}
@@ -1489,22 +1495,22 @@ unsigned long RawFile::preview_offset(void)
 	if (type == Exiv2::ImageType::cr2)
 		{
 		val = find(0x111, Group::ifd0);
-		if (val) return val->toLong();
+		if (val) return val->toInt64();
 
 		return 0;
 		}
 
 	val = find(0x201, Group::sub0_0);
-	if (val) return val->toLong();
+	if (val) return val->toInt64();
 
 	val = find(0x201, Group::ifd0);
-	if (val) return val->toLong();
+	if (val) return val->toInt64();
 
 	val = find(0x201, Group::ignr); // for PEF files, originally it was probably ifd2
-	if (val) return val->toLong();
+	if (val) return val->toInt64();
 
 	val = find(0x111, Group::sub0_1); // dng
-	if (val) return val->toLong();
+	if (val) return val->toInt64();
 
 	return 0;
 }
