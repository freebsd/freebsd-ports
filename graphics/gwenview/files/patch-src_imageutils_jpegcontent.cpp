--- src/imageutils/jpegcontent.cpp.orig	2007-09-15 19:46:17.000000000 +0600
+++ src/imageutils/jpegcontent.cpp	2009-01-09 14:24:04.000000000 +0500
@@ -589,7 +589,8 @@
 QImage JPEGContent::thumbnail() const {
 	QImage image;
 	if (!d->mExifData.empty()) {
-		Exiv2::DataBuf thumbnail = d->mExifData.copyThumbnail();
+		Exiv2::ExifThumbC thumb(d->mExifData);
+		Exiv2::DataBuf const thumbnail = thumb.copy();
 		image.loadFromData(thumbnail.pData_, thumbnail.size_);
 	}
 	return image;
@@ -611,7 +612,8 @@
 		return;
 	}
 	
-	d->mExifData.setJpegThumbnail((unsigned char*)array.data(), array.size());
+	Exiv2::ExifThumb thumb(d->mExifData);
+	thumb.setJpegThumbnail((unsigned char*)array.data(), array.size());
 }
 
 
