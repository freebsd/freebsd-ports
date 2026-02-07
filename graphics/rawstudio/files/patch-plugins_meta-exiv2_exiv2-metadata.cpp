--- plugins/meta-exiv2/exiv2-metadata.cpp.orig	2011-02-26 23:13:39 UTC
+++ plugins/meta-exiv2/exiv2-metadata.cpp
@@ -22,6 +22,8 @@
 #include <iomanip>
 #include <exiv2/image.hpp>
 #include <exiv2/exif.hpp>
+#include <exiv2/version.hpp>
+#include <exiv2/error.hpp>
 #include <assert.h>
 #include "exiv2-metadata.h"
 #include <math.h>
@@ -94,7 +96,7 @@ gboolean
 exiv2_load_meta_interface(const gchar *service, RAWFILE *rawfile, guint offset, RSMetadata *meta)
 {
 	try {
-		Image::AutoPtr img = ImageFactory::open((byte*)raw_get_map(rawfile), raw_get_filesize(rawfile));
+		Image::UniquePtr img { ImageFactory::open((byte*)raw_get_map(rawfile), raw_get_filesize(rawfile)) };
 		img->readMetadata();
 		ExifData &exifData = img->exifData();
 
@@ -121,7 +123,7 @@ exiv2_load_meta_interface(const gchar *service, RAWFIL
 			i = orientation(exifData);
 			if (i != exifData.end())
 			{
-				switch (i->getValue()->toLong())
+				switch (i->getValue()->toInt64())
 				{
 						case 6: meta->orientation = 90;
 							break;
@@ -173,7 +175,7 @@ exiv2_load_meta_interface(const gchar *service, RAWFIL
 #if EXIV2_TEST_VERSION(0,19,0)
 			i = isoSpeed(exifData);
 			if (i != exifData.end())
-				meta->iso = i->toLong();
+				meta->iso = i->toInt64();
 
 			/* Text based Lens Identifier */
 			i = lensName(exifData);
@@ -181,7 +183,7 @@ exiv2_load_meta_interface(const gchar *service, RAWFIL
 			{
 				TypeId type = i->typeId();
 				if (type == unsignedShort || type == unsignedLong || type == signedShort || type == signedLong || type == unsignedByte || type == signedByte)
-					meta->lens_id = i->toLong();
+					meta->lens_id = i->toInt64();
 				else if (type == asciiString || type == string)
 					meta->fixed_lens_identifier = g_strdup(i->toString().c_str());
 			}
@@ -223,7 +225,7 @@ exiv2_load_meta_interface(const gchar *service, RAWFIL
 			if (i == exifData.end())
 				i = exifData.findKey(ExifKey("Exif.NikonLd3.MinFocalLength"));
 			if (i != exifData.end())
-				meta->lens_min_focal = 5.0 * pow(2.0, i->toLong()/24.0);
+				meta->lens_min_focal = 5.0 * pow(2.0, i->toInt64()/24.0);
 
 			i = exifData.findKey(ExifKey("Exif.NikonLd1.MaxFocalLength"));
 			if (i == exifData.end())
@@ -231,7 +233,7 @@ exiv2_load_meta_interface(const gchar *service, RAWFIL
 			if (i == exifData.end())
 				i = exifData.findKey(ExifKey("Exif.NikonLd3.MaxFocalLength"));
 			if (i != exifData.end())
-				meta->lens_max_focal = 5.0 * pow(2.0, i->toLong()/24.0);
+				meta->lens_max_focal = 5.0 * pow(2.0, i->toInt64()/24.0);
 
 			i = exifData.findKey(ExifKey("Exif.NikonLd1.MaxApertureAtMinFocal"));
 			if (i == exifData.end())
@@ -239,7 +241,7 @@ exiv2_load_meta_interface(const gchar *service, RAWFIL
 			if (i == exifData.end())
 				i = exifData.findKey(ExifKey("Exif.NikonLd3.MaxApertureAtMinFocal"));
 			if (i != exifData.end())
-				meta->lens_min_aperture = i->toLong()/12.0;
+				meta->lens_min_aperture = i->toInt64()/12.0;
 			
 			i = exifData.findKey(ExifKey("Exif.NikonLd1.MaxApertureAtMaxFocal"));
 			if (i == exifData.end())
@@ -247,7 +249,7 @@ exiv2_load_meta_interface(const gchar *service, RAWFIL
 			if (i == exifData.end())
 				i = exifData.findKey(ExifKey("Exif.NikonLd3.MaxApertureAtMaxFocal"));
 			if (i != exifData.end())
-				meta->lens_max_aperture = i->toLong()/12.0;
+				meta->lens_max_aperture = i->toInt64()/12.0;
 				
 			/* Fuji */
 			i = exifData.findKey(ExifKey("Exif.Fujifilm.MinFocalLength"));
