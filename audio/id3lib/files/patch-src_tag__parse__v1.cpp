
$FreeBSD$

--- src/tag_parse_v1.cpp.orig	Mon Sep 11 08:34:06 2000
+++ src/tag_parse_v1.cpp	Sun Jul 21 15:13:19 2002
@@ -67,7 +67,7 @@
   {
     const size_t data_size = ID3_V1_LEN - ID3_V1_LEN_ID;
     uchar tag_bytes[data_size];
-    file.read(tag_bytes, data_size);
+    file.read((char*) tag_bytes, data_size);
     if (file.gcount() != data_size)
     {
       return num_bytes;
