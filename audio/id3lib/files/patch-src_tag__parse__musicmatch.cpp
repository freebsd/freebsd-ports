
$FreeBSD$

--- src/tag_parse_musicmatch.cpp.orig	Mon Sep 11 09:46:32 2000
+++ src/tag_parse_musicmatch.cpp	Sun Jul 21 15:13:19 2002
@@ -221,7 +221,7 @@
     return 0;
   }
 
-  file.seekg(tag_end - tag_size);
+  file.seekg((size_t) tag_end - tag_size);
   tag_beg = file.tellg();
 
   // Now calculate the actual offsets
@@ -229,17 +229,17 @@
   offsets[0] = tag_beg;
   for (size_t i = 0; i < 4; ++i)
   {
-    offsets[i+1] = offsets[i] + section_sizes[i];
+    offsets[i+1] = offsets[i] + (streampos) section_sizes[i];
   }
 
   // now check for a tag header and adjust the tag_beg pointer appropriately
   if (tag_beg >= 256)
   {
-    file.seekg(tag_beg - 256);
+    file.seekg((size_t) tag_beg - 256);
     file.read(sig, 8);
     if (memcmp(sig, "18273645", 8) == 0)
     {
-      file.seekg(tag_beg - 256);
+      file.seekg((size_t) tag_beg - 256);
       tag_beg = file.tellg();
       file.ignore(256);
     }
@@ -267,7 +267,7 @@
   {
     // no image binary.  don't do anything.
   }
-  else if (offsets[0] + 4 + nImgSize > static_cast<size_t>(offsets[2]))
+  else if ((size_t) offsets[0] + 4 + nImgSize > static_cast<size_t>(offsets[2]))
   {
     // Ack!  The image size given extends beyond the next offset!  This is 
     // not good...  log?
@@ -275,7 +275,7 @@
   else
   {
     uchar* img_data = new uchar[nImgSize];
-    file.read(img_data, nImgSize);
+    file.read((char*) img_data, nImgSize);
     ID3_Frame* frame = new ID3_Frame(ID3FID_PICTURE);
     if (frame)
     {
