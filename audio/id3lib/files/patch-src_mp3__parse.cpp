--- src/mp3_parse.cpp.orig	2003-03-02 00:23:00 UTC
+++ src/mp3_parse.cpp
@@ -465,7 +465,7 @@ bool Mp3Info::Parse(ID3_Reader& reader, 
   // from http://www.xingtech.com/developer/mp3/
 
   const size_t VBR_HEADER_MIN_SIZE = 8;     // "xing" + flags are fixed
-  const size_t VBR_HEADER_MAX_SIZE = 116;   // frames, bytes, toc and scale are optional
+  const size_t VBR_HEADER_MAX_SIZE = 120;   // frames, bytes, toc and scale are optional
 
   if (mp3size >= vbr_header_offest + VBR_HEADER_MIN_SIZE) 
   {
