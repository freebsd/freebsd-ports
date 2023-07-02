--- database/exifFunctions.cpp.orig	2021-03-05 05:27:44 UTC
+++ database/exifFunctions.cpp
@@ -123,7 +123,7 @@ int exifDefaultRotation(const std::string fullFilename
         int exifOrientation;
         try
         {
-            exifOrientation = (int) exifData["Exif.Image.Orientation"].value().toLong();
+            exifOrientation = (int) exifData["Exif.Image.Orientation"].value().toInt64();
         }
         catch (...)
         {
@@ -295,7 +295,7 @@ int exifRating(const std::string fullFilename)
         std::string maker = exifData["Exif.Image.Make"].toString();
         if (maker.compare("Canon") == 0)
         {
-            return min(5,max(0,(int) xmpData["Xmp.xmp.Rating"].toLong()));
+            return min(5,max(0,(int) xmpData["Xmp.xmp.Rating"].toInt64()));
         }
         return 0;
     }
