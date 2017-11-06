--- rtengine/imagedata.cc.orig	2017-01-26 22:12:23 UTC
+++ rtengine/imagedata.cc
@@ -444,7 +444,7 @@ void ImageData::extractInfo ()
                         if (baseIsoTag) {
                             std::string isoData = baseIsoTag->valueToString();
                             if (isoData.size() > 1) {
-                                iso_speed = stoi(isoData);
+                                iso_speed = std::stoi(isoData);
                             }
                         }
                     }
