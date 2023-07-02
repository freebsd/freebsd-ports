--- src/hugin_base/panodata/SrcPanoImage.cpp.orig	2022-05-26 16:18:56 UTC
+++ src/hugin_base/panodata/SrcPanoImage.cpp
@@ -384,7 +384,7 @@ bool SrcPanoImage::readEXIF()
                     pos = xmpData.findKey(Exiv2::XmpKey("Xmp.GPano.CroppedAreaImageWidthPixels"));
                     if (pos != xmpData.end())
                     {
-                        croppedWidth = pos->toLong();
+                        croppedWidth = pos->toInt64();
                     }
                     else
                     {
@@ -394,7 +394,7 @@ bool SrcPanoImage::readEXIF()
                     pos = xmpData.findKey(Exiv2::XmpKey("Xmp.GPano.CroppedAreaImageHeightPixels"));
                     if (pos != xmpData.end())
                     {
-                        croppedHeight = pos->toLong();
+                        croppedHeight = pos->toInt64();
                     }
                     else
                     {
@@ -408,7 +408,7 @@ bool SrcPanoImage::readEXIF()
                         double hfov = 0;
                         if (pos != xmpData.end())
                         {
-                            hfov = 360 * croppedWidth / (double)pos->toLong();
+                            hfov = 360 * croppedWidth / (double)pos->toInt64();
                         }
                         else
                         {
@@ -419,7 +419,7 @@ bool SrcPanoImage::readEXIF()
                         pos = xmpData.findKey(Exiv2::XmpKey("Xmp.GPano.FullPanoHeightPixels"));
                         if (pos != xmpData.end())
                         {
-                            fullHeight = pos->toLong();
+                            fullHeight = pos->toInt64();
                         }
                         else
                         {
@@ -430,7 +430,7 @@ bool SrcPanoImage::readEXIF()
                         pos = xmpData.findKey(Exiv2::XmpKey("Xmp.GPano.CroppedAreaTopPixels"));
                         if (pos != xmpData.end())
                         {
-                            cropTop = pos->toLong();
+                            cropTop = pos->toInt64();
                         }
                         else
                         {
