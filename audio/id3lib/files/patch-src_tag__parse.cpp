
$FreeBSD$

--- src/tag_parse.cpp.orig	Fri Sep 15 01:54:08 2000
+++ src/tag_parse.cpp	Sun Jul 21 15:13:19 2002
@@ -178,7 +178,7 @@
     return 0;
   }
   uchar header[ID3_TAGHEADERSIZE];
-  file.read(header, ID3_TAGHEADERSIZE);
+  file.read((char*) header, ID3_TAGHEADERSIZE);
   if (file.gcount() != ID3_TAGHEADERSIZE)
   {
     return 0;
@@ -188,7 +188,7 @@
   if (tagSize > 0)
   {
     uchar* bin = new uchar[tagSize];
-    file.read(bin, tagSize - ID3_TagHeader::SIZE);
+    file.read((char*) bin, tagSize - ID3_TagHeader::SIZE);
     if (tagSize != (size_t)file.gcount())
     {
       // log this...
