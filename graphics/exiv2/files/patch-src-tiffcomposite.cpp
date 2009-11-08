Index: tiffcomposite.cpp
===================================================================
--- src/tiffcomposite.cpp	(revision 1742)
+++ src/tiffcomposite.cpp	(revision 1743)
@@ -688,9 +688,13 @@
 
     uint32_t TiffMnEntry::doCount() const
     {
-        // Count of tag Exif.Photo.MakerNote is the size of the Makernote in bytes
+        if (!mn_) {
+            return TiffEntryBase::doCount();
+        }
+        // Count of IFD makernote in tag Exif.Photo.MakerNote is the size of the
+        // Makernote in bytes
         assert(tiffType() == ttUndefined);
-        return size();
+        return mn_->size();
     }
 
     uint32_t TiffArrayEntry::doCount() const
