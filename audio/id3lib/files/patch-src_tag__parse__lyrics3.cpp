
$FreeBSD$

--- src/tag_parse_lyrics3.cpp.orig	Mon Sep 11 08:34:06 2000
+++ src/tag_parse_lyrics3.cpp	Sun Jul 21 15:13:19 2002
@@ -200,7 +200,7 @@
       // reserve enough space for lyrics3 + id3v1 tag
       const size_t max_lyr_size = 11 + 5100 + 9 + 128;
 
-      size_t lyr_buffer_size = MIN(max_lyr_size, file.tellg());
+      size_t lyr_buffer_size = MIN(max_lyr_size, (size_t) file.tellg());
 
       file.seekg(- static_cast<long>(lyr_buffer_size), ios::cur);
       if (!file)
@@ -274,7 +274,7 @@
       
       // Using binary minus rather than unary minus to avoid compiler warning
       
-      file.seekg(- MIN(file.tellg(), 
+      file.seekg(- MIN((size_t) file.tellg(), 
                        (static_cast<long>(lyr_size) + 6 + 9 + 3)), ios::cur);
       if (!file)
       {
