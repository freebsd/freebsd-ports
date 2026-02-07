--- librawstudio/rs-exif.cc.orig	2011-02-15 17:28:05 UTC
+++ librawstudio/rs-exif.cc
@@ -21,6 +21,8 @@
 #include <iomanip>
 #include <exiv2/image.hpp>
 #include <exiv2/exif.hpp>
+#include <exiv2/error.hpp>
+#include <exiv2/version.hpp>
 #include "rs-exif.h"
 #include <assert.h>
 #include "rs-library.h"
@@ -128,7 +130,7 @@ rs_exif_load_from_file(const gchar *filename)
 	RS_EXIF_DATA *exif_data;
 	try
 	{
-		Exiv2::Image::AutoPtr image = Exiv2::ImageFactory::open(filename);
+		Exiv2::Image::UniquePtr image { Exiv2::ImageFactory::open(filename) };
 		assert(image.get() != 0);
 		image->readMetadata();
 
@@ -136,7 +138,7 @@ rs_exif_load_from_file(const gchar *filename)
 
 		exif_data_init(exif_data);
 	}
-	catch (Exiv2::AnyError& e)
+	catch (Exiv2::Error& e)
 	{
 		g_warning("Could not load EXIF data from file %s", filename);
 		return NULL;
@@ -151,8 +153,8 @@ rs_exif_load_from_rawfile(RAWFILE *rawfile)
 	RS_EXIF_DATA *rs_exif_data;
 	try
 	{
-		Exiv2::Image::AutoPtr image = Exiv2::ImageFactory::open(
-			(const Exiv2::byte*) raw_get_map(rawfile), raw_get_filesize(rawfile));
+		Exiv2::Image::UniquePtr image { Exiv2::ImageFactory::open(
+			(const Exiv2::byte*) raw_get_map(rawfile), raw_get_filesize(rawfile)) };
 
 		assert(image.get() != 0);
 		image->readMetadata();
@@ -161,7 +163,7 @@ rs_exif_load_from_rawfile(RAWFILE *rawfile)
 
 		exif_data_init(rs_exif_data);
 	}
-	catch (Exiv2::AnyError& e)
+	catch (Exiv2::Error& e)
 	{
 		g_warning("Could not load EXIF data");
 		return NULL;
@@ -179,7 +181,7 @@ rs_exif_add_to_file(RS_EXIF_DATA *d, Exiv2::IptcData &
 	try
 	{
 		Exiv2::ExifData *data = (Exiv2::ExifData *) d;
-		Exiv2::Image::AutoPtr image = Exiv2::ImageFactory::open(filename);
+		Exiv2::Image::UniquePtr image { Exiv2::ImageFactory::open(filename) };
 
 		/* Copy EXIF to XMP */
 #if EXIV2_TEST_VERSION(0,17,0)
@@ -194,7 +196,7 @@ rs_exif_add_to_file(RS_EXIF_DATA *d, Exiv2::IptcData &
 		image->setIptcData(iptc_data);
 		image->writeMetadata();
 	}
-	catch (Exiv2::AnyError& e)
+	catch (Exiv2::Error& e)
 	{
 		g_warning("Couldn't add EXIF data to %s", filename);
 	}
@@ -263,7 +265,7 @@ rs_add_tags_exif(RS_EXIF_DATA *d, const gchar *input_f
 
 	glong items_written;
 	gunichar2 *w = g_utf8_to_utf16(xpkeyw->str, -1, NULL, &items_written, NULL);
-	Exiv2::Value::AutoPtr v = Exiv2::Value::create(Exiv2::unsignedByte);
+	Exiv2::Value::UniquePtr v { Exiv2::Value::create(Exiv2::unsignedByte) };
 	v->read((const Exiv2::byte*)w, items_written * sizeof(gunichar2), Exiv2::invalidByteOrder);
 	Exiv2::ExifKey key = Exiv2::ExifKey("Exif.Image.XPKeywords");
 	data->add(key, v.get());
