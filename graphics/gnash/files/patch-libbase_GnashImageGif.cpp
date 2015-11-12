--- libbase/GnashImageGif.cpp.orig	2012-01-19 19:17:48 UTC
+++ libbase/GnashImageGif.cpp
@@ -121,7 +121,11 @@ GifInput::GifInput(boost::shared_ptr<IOC
 GifInput::~GifInput()
 {
     // Clean up allocated data.
+#if GIFLIB_MAJOR == 5 && GIFLIB_MINOR >= 1 || GIFLIB_MAJOR > 5
+    DGifCloseFile(_gif, NULL);
+#else
     DGifCloseFile(_gif);
+#endif
 }
 
 size_t
@@ -269,7 +273,11 @@ GifInput::processRecord(GifRecordType re
 void
 GifInput::read()
 {
+#if GIFLIB_MAJOR >= 5
+    _gif = DGifOpen(_inStream.get(), &readData, NULL); 
+#else
     _gif = DGifOpen(_inStream.get(), &readData); 
+#endif
 
     GifRecordType record;
 
