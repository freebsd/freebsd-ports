--- Bundles/FLAC/FLAC.h.orig	2006-03-21 11:11:19.000000000 +0100
+++ Bundles/FLAC/FLAC.h	2008-03-27 17:23:35.000000000 +0100
@@ -31,7 +31,7 @@
 
 @interface FLAC : NSObject <CynthiuneBundle, Format>
 {
-  FLAC__FileDecoder *fileDecoder;
+  FLAC__StreamDecoder *fileDecoder;
 
   unsigned int bitsPerSample;
   unsigned int duration;
