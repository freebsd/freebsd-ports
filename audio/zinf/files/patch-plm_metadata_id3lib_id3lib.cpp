--- plm/metadata/id3lib/id3lib.cpp.orig	2004-02-14 01:51:03 UTC
+++ plm/metadata/id3lib/id3lib.cpp
@@ -363,7 +363,7 @@ bool ID3lib::ReadMetaData(const char* ur
     assert(url);
     assert(metadata);
 
-    char *ptr = strrchr(url, '.');
+    const char *ptr = strrchr(url, '.');
     if (ptr == NULL)
         return false;
 
@@ -421,7 +421,7 @@ bool ID3lib::WriteMetaData(const char* u
     char      dummy[20];
     bool      bWriteID3v1, bWriteID3v2;
     luint     whichTags;
-    char     *ptr;
+    const char *ptr;
 
     ptr = strrchr(url, '.');
     if (ptr == NULL)
@@ -485,7 +485,7 @@ void ID3lib::LookupGenre(int genreId, ch
 
 bool ID3lib::readMetadata(const std::string&url, map_type& pairs)
 {
-    char *ptr = strrchr(url.c_str(), '.');
+    const char *ptr = strrchr(url.c_str(), '.');
     if (ptr == NULL)
         return false;
 
