--- core/libs/metadataengine/engine/metaengine_item.cpp.orig	2023-03-12 13:19:02 UTC
+++ core/libs/metadataengine/engine/metaengine_item.cpp
@@ -127,7 +127,7 @@ QSize MetaEngine::getItemDimensions() const
 
         if ((it != exifData.end()) && it->count())
         {
-            width = it->toLong();
+            width = it->toInt64();
         }
 
         Exiv2::ExifKey key2("Exif.Photo.PixelYDimension");
@@ -135,7 +135,7 @@ QSize MetaEngine::getItemDimensions() const
 
         if ((it2 != exifData.end()) && it2->count())
         {
-            height = it2->toLong();
+            height = it2->toInt64();
         }
 
         if ((width != -1) && (height != -1))
@@ -153,7 +153,7 @@ QSize MetaEngine::getItemDimensions() const
 
         if ((it3 != exifData.end()) && it3->count())
         {
-            width = it3->toLong();
+            width = it3->toInt64();
         }
 
         Exiv2::ExifKey key4("Exif.Image.ImageLength");
@@ -161,7 +161,7 @@ QSize MetaEngine::getItemDimensions() const
 
         if ((it4 != exifData.end()) && it4->count())
         {
-            height = it4->toLong();
+            height = it4->toInt64();
         }
 
         if ((width != -1) && (height != -1))
@@ -320,7 +320,7 @@ MetaEngine::ImageOrientation MetaEngine::getItemOrient
 
         if ((it != exifData.end()) && it->count())
         {
-            orientation = it->toLong();
+            orientation = it->toInt64();
 
             //qCDebug(DIGIKAM_METAENGINE_LOG) << "Orientation => Exif.MinoltaCs7D.Rotation =>" << (int)orientation;
 
@@ -347,7 +347,7 @@ MetaEngine::ImageOrientation MetaEngine::getItemOrient
 
         if ((it != exifData.end()) && it->count())
         {
-            orientation = it->toLong();
+            orientation = it->toInt64();
 
             //qCDebug(DIGIKAM_METAENGINE_LOG) << "Orientation => Exif.MinoltaCs5D.Rotation =>" << (int)orientation;
 
@@ -376,7 +376,7 @@ MetaEngine::ImageOrientation MetaEngine::getItemOrient
 
         if ((it != exifData.end()) && it->count())
         {
-            orientation = it->toLong();
+            orientation = it->toInt64();
 
             //qCDebug(DIGIKAM_METAENGINE_LOG) << "Orientation => Exif.Image.Orientation =>" << (int)orientation;
 
