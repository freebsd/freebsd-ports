--- libbase/GnashImageGif.cpp.orig	2016-07-21 12:25:09 UTC
+++ libbase/GnashImageGif.cpp
@@ -120,7 +120,7 @@ GifInput::GifInput(std::shared_ptr<IOCha
 GifInput::~GifInput()
 {
     // Clean up allocated data.
-#if GIFLIB_MAJOR==5 && GIFLIB_MINOR==1
+#if GIFLIB_MAJOR==5 && GIFLIB_MINOR>=1
 	DGifCloseFile(_gif, 0);
 #else
 	DGifCloseFile(_gif);
