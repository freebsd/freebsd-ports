--- src/imageutils/jpegcontent.cpp.orig	Fri Jul  6 18:37:46 2007
+++ src/imageutils/jpegcontent.cpp	Fri Jul  6 18:38:24 2007
@@ -255,11 +255,11 @@
 	Exiv2::Image::AutoPtr image;
 	try {
 		image = Exiv2::ImageFactory::open((unsigned char*)data.data(), data.size());
+	image->readMetadata();
 	} catch (Exiv2::Error&) {
 		kdError() << "Could not load image with Exiv2\n";
 		return false;
 	}
-	image->readMetadata();
 
 	d->mExifData = image->exifData();
 	d->mComment = QString::fromUtf8( image->comment().c_str() );
