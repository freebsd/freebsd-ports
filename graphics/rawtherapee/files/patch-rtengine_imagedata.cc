--- rtengine/imagedata.cc.orig	2018-12-18 19:12:08 UTC
+++ rtengine/imagedata.cc
@@ -413,7 +413,7 @@ FrameData::FrameData (rtexif::TagDirectory* frameRootD
                         if (baseIsoTag) {
                             std::string isoData = baseIsoTag->valueToString();
                             if (isoData.size() > 1) {
-                                iso_speed = stoi(isoData);
+                                iso_speed = std::stoi(isoData);
                             }
                         }
                     }
