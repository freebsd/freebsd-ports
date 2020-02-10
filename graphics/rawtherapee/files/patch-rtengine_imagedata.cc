--- rtengine/imagedata.cc.orig	2020-02-04 06:39:52 UTC
+++ rtengine/imagedata.cc
@@ -506,7 +506,7 @@ FrameData::FrameData(rtexif::TagDirectory* frameRootDi
                         if (baseIsoTag) {
                             std::string isoData = baseIsoTag->valueToString();
                             if (isoData.size() > 1) {
-                                iso_speed = stoi(isoData);
+                                iso_speed = std::stoi(isoData);
                             }
                         }
                     }
