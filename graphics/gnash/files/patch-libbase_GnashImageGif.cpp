--- libbase/GnashImageGif.cpp.orig	2012-01-19 19:17:48 UTC
+++ libbase/GnashImageGif.cpp
@@ -269,7 +269,11 @@ GifInput::processRecord(GifRecordType re
 void
 GifInput::read()
 {
+#if GIFLIB_MAJOR >= 5
+    _gif = DGifOpen(_inStream.get(), &readData, NULL); 
+#else
     _gif = DGifOpen(_inStream.get(), &readData); 
+#endif
 
     GifRecordType record;
 
