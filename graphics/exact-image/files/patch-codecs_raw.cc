--- codecs/raw.cc.orig	2011-01-14 16:30:13 UTC
+++ codecs/raw.cc
@@ -71,9 +71,8 @@ bool RAWCodec::writeImage (std::ostream* stream, Image
   if (!image.getRawData())
     return false;
 
-  return stream->write ((char*)image.getRawData(), image.stride()*image.h)
-    /* ==
-       (size_t) image.stride()*image.h*/;
+  stream->write ((char*)image.getRawData(), image.stride()*image.h);
+  return stream->good();
 }
 
 RAWCodec raw_loader;
