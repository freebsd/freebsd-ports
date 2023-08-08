--- core/imwriteJpeg.cpp.orig	2021-03-05 05:27:44 UTC
+++ core/imwriteJpeg.cpp
@@ -186,7 +186,7 @@ static void remove_exif_keys(Exiv2::ExifData &exifData
             {
                 exifData.erase(pos);
             }
-        } catch (Exiv2::AnyError &e) {
+        } catch (Exiv2::Error &e) {
             //catch invalid tag
         }
     }
