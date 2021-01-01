--- ui/gfx/codec/jpeg_codec.cc.orig	2019-12-12 12:41:33 UTC
+++ ui/gfx/codec/jpeg_codec.cc
@@ -207,6 +207,7 @@ bool JPEGCodec::Decode(const unsigned char* input, siz
     case JCS_GRAYSCALE:
     case JCS_RGB:
     case JCS_YCbCr:
+#ifdef JCS_EXTENSIONS
       // Choose an output colorspace and return if it is an unsupported one.
       // Same as JPEGCodec::Encode(), libjpeg-turbo supports all input formats
       // used by Chromium (i.e. RGBA and BGRA) and we just map the input
@@ -223,6 +224,9 @@ bool JPEGCodec::Decode(const unsigned char* input, siz
         NOTREACHED() << "Invalid pixel format";
         return false;
       }
+#else
+      cinfo.out_color_space = JCS_RGB;
+#endif
       break;
     case JCS_CMYK:
     case JCS_YCCK:
