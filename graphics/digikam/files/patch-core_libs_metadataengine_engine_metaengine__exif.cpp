--- core/libs/metadataengine/engine/metaengine_exif.cpp.orig	2023-03-12 13:19:02 UTC
+++ core/libs/metadataengine/engine/metaengine_exif.cpp
@@ -80,7 +80,7 @@ bool MetaEngine::canWriteExif(const QString& filePath)
     catch (Exiv2::AnyError& e)
     {
         qCCritical(DIGIKAM_METAENGINE_LOG) << "Cannot check Exif access mode with Exiv2:(Error #"
-                                           << e.code() << ": " << QString::fromStdString(e.what()) << ")";
+                                           << static_cast<int>(e.code()) << ": " << QString::fromStdString(e.what()) << ")";
     }
     catch (...)
     {
@@ -739,7 +739,7 @@ bool MetaEngine::getExifTagLong(const char* exifTagNam
 
         if ((it != exifData.end()) && (it->count() > 0))
         {
-            val = it->toLong(component);
+            val = it->toInt64(component);
 
             return true;
         }
@@ -812,7 +812,7 @@ QVariant MetaEngine::getExifTagVariant(const char* exi
                 {
                     if ((int)it->count() > component)
                     {
-                        return QVariant((int)it->toLong(component));
+                        return QVariant((int)it->toInt64(component));
                     }
                     else
                     {
@@ -915,7 +915,7 @@ QString MetaEngine::getExifTagString(const char* exifT
             QString tagValue;
             QString key = QLatin1String(it->key().c_str());
 
-            if ((key == QLatin1String("Exif.CanonCs.LensType")) && (it->toLong() == 65535))
+            if ((key == QLatin1String("Exif.CanonCs.LensType")) && (it->toInt64() == 65535))
             {
                 // FIXME: workaround for a possible crash in Exiv2 pretty-print function for the Exif.CanonCs.LensType.
 
@@ -987,12 +987,12 @@ QImage MetaEngine::getExifThumbnail(bool fixOrientatio
         Exiv2::ExifThumbC thumb(d->exifMetadata());
         Exiv2::DataBuf const c1 = thumb.copy();
 
-        if (c1.size_ == 0)
+        if (c1.size() == 0)
         {
             return thumbnail;
         }
 
-        thumbnail.loadFromData(c1.pData_, c1.size_);
+        thumbnail.loadFromData(c1.c_data(), c1.size());
 
         if (!thumbnail.isNull())
         {
@@ -1010,7 +1010,7 @@ QImage MetaEngine::getExifThumbnail(bool fixOrientatio
 
                 if (it != exifData.end() && it->count())
                 {
-                    long orientation = it->toLong();
+                    long orientation = it->toInt64();
 
                     //qCDebug(DIGIKAM_METAENGINE_LOG) << "Exif Thumbnail Orientation: " << (int)orientation;
 
@@ -1092,12 +1092,12 @@ bool MetaEngine::setTiffThumbnail(const QImage& thumbI
 
         Exiv2::ExifData::const_iterator pos = d->exifMetadata().findKey(Exiv2::ExifKey("Exif.Image.NewSubfileType"));
 
-        if ((pos == d->exifMetadata().end()) || (pos->count() != 1) || (pos->toLong() != 0))
+        if ((pos == d->exifMetadata().end()) || (pos->count() != 1) || (pos->toInt64() != 0))
         {
 
 #if EXIV2_TEST_VERSION(0,27,0)
 
-            throw Exiv2::Error(Exiv2::kerErrorMessage, "Exif.Image.NewSubfileType missing or not set as main image");
+            throw Exiv2::Error(Exiv2::ErrorCode::kerErrorMessage, "Exif.Image.NewSubfileType missing or not set as main image");
 
 #else
 
@@ -1136,9 +1136,9 @@ bool MetaEngine::setTiffThumbnail(const QImage& thumbI
             Exiv2::DataBuf buf((Exiv2::byte*)data.data(), data.size());
             Exiv2::ULongValue val;
             val.read("0");
-            val.setDataArea(buf.pData_, buf.size_);
+            val.setDataArea(buf.c_data(), buf.size());
             d->exifMetadata()["Exif.SubImage1.JPEGInterchangeFormat"]       = val;
-            d->exifMetadata()["Exif.SubImage1.JPEGInterchangeFormatLength"] = uint32_t(buf.size_);
+            d->exifMetadata()["Exif.SubImage1.JPEGInterchangeFormatLength"] = uint32_t(buf.size());
             d->exifMetadata()["Exif.SubImage1.Compression"]                 = uint16_t(6);          // JPEG (old-style)
             d->exifMetadata()["Exif.SubImage1.NewSubfileType"]              = uint32_t(1);          // Thumbnail image
 
@@ -1261,7 +1261,7 @@ MetaEngine::MetaDataMap MetaEngine::getExifTagsDataLis
             {
                 tagValue = QString::number(md->value().size());
             }
-            else if (key == QLatin1String("Exif.CanonCs.LensType") && md->toLong() == 65535)
+            else if (key == QLatin1String("Exif.CanonCs.LensType") && md->toInt64() == 65535)
             {
                 // FIXME: workaround for a possible crash in Exiv2 pretty-print function for the Exif.CanonCs.LensType.
 
