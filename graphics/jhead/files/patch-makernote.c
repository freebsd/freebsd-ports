--- jhead-2.60.orig/makernote.c	2006-05-18 00:48:56.000000000 +0400
+++ makernote.c	2006-12-18 09:57:32.000000000 +0300
@@ -147,6 +147,27 @@
         }
     }
 }
+//
+//--------------------------------------------------------------------------
+// Process exif format directory, as used by Nikon maker note
+//--------------------------------------------------------------------------
+void ProcessNikonMakerNoteDir(unsigned char *MakerNote)
+{
+    unsigned short iso;
+
+    if (DumpExifMap){
+        printf("(Nikon makernote)\n");
+    }
+
+    iso = Get16u(MakerNote + 20 + 12 + 10);     // 20 bytes MakerNote ID ("Nikon" + padding), then TIFF header
+
+    if (ShowTags){
+        printf("ISO derived from Nikon MakerNote: %d\n",iso);
+    }
+
+    if (!ImageInfo.ISOequivalent)
+        ImageInfo.ISOequivalent = iso;
+}
 
 //--------------------------------------------------------------------------
 // Show generic maker note - just hex bytes.
@@ -174,6 +195,8 @@
 {
     if (strstr(ImageInfo.CameraMake, "Canon")){
         ProcessCanonMakerNoteDir(ValuePtr, OffsetBase, ExifLength);
+    }else if (strncmp((char *)ValuePtr, "Nikon", 5) == 0){
+        ProcessNikonMakerNoteDir(ValuePtr);
     }else{
         if (ShowTags){
             ShowMakerNoteGeneric(ValuePtr, ByteCount);
