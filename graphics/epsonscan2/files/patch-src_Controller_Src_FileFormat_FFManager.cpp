--- src/Controller/Src/FileFormat/FFManager.cpp.orig	2021-11-25 00:56:58 UTC
+++ src/Controller/Src/FileFormat/FFManager.cpp
@@ -176,6 +176,9 @@ namespace epsonscan
                     return kFKWriterTypePnm;
                 case kSDIImageFormatBMP:
                     return kFKWriterTypeBmp;
+		case kSDIImageFormatRaw:
+		case kSDIImageFormatColorJpegMonoPNM:
+		    break;
             }
             return kFKWriterTypeBmp;
         }
