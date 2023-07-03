--- lib/kpaexif/DatabaseElement.cpp.orig	2023-03-25 09:46:12 UTC
+++ lib/kpaexif/DatabaseElement.cpp
@@ -77,7 +77,7 @@ QString Exif::IntExifElement::queryString() const
 QVariant Exif::IntExifElement::valueFromExif(Exiv2::ExifData &data) const
 {
     if (data[m_tag].count() > 0)
-        return QVariant { (int)data[m_tag].toLong() };
+        return QVariant { (int)data[m_tag].toInt64() };
     else
         return QVariant { (int)0 };
 }
