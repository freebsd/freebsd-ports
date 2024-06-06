TagLib::AudioProperties::length() is deprecated in Taglib 2.x.

--- src/tags/mp4_header.cc.orig	2016-06-24 14:57:32 UTC
+++ src/tags/mp4_header.cc
@@ -105,7 +105,7 @@ et_mp4_header_read_file_info (GFile *file,
     ETFileInfo->bitrate = properties->bitrate ();
     ETFileInfo->samplerate = properties->sampleRate ();
     ETFileInfo->mode = properties->channels ();
-    ETFileInfo->duration = properties->length ();
+    ETFileInfo->duration = properties->lengthInSeconds ();
 
     return TRUE;
 }
