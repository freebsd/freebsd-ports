--- src/photos/PhotoMetadata.vala.orig	2019-03-30 21:05:25 UTC
+++ src/photos/PhotoMetadata.vala
@@ -276,7 +276,7 @@ public class PhotoMetadata : MediaMetadata {
         exiv2 = new GExiv2.Metadata();
         exif = null;
         
-        exiv2.open_buf(buffer, length);
+        exiv2.open_buf(buffer[0:length]);
         exif = Exif.Data.new_from_data(buffer, length);
         source_name = "<memory buffer %d bytes>".printf(length);
     }
@@ -285,8 +285,8 @@ public class PhotoMetadata : MediaMetadata {
         exiv2 = new GExiv2.Metadata();
         exif = null;
         
-        exiv2.from_app1_segment(buffer.get_data(), (long) buffer.get_size());
-        exif = Exif.Data.new_from_data(buffer.get_data(), buffer.get_size());
+        exiv2.from_app1_segment(buffer.get_data());
+        exif = Exif.Data.new_from_data(buffer.get_data(), (long) buffer.get_size());
         source_name = "<app1 segment %zu bytes>".printf(buffer.get_size());
     }
     
