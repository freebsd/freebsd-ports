--- src/Controller/Src/FileFormat/FFManager.cpp.orig	2024-09-12 07:10:36 UTC
+++ src/Controller/Src/FileFormat/FFManager.cpp
@@ -180,6 +180,9 @@ namespace epsonscan
                     return kFKWriterTypePnm;
                 case kSDIImageFormatBMP:
                     return kFKWriterTypeBmp;
+	        case kSDIImageFormatRaw:
+		case kSDIImageFormatColorJpegMonoPNM:
+		    break;
                 case kSDIImageFormatOFD:
                     return kFKWriterTypeOFD;
             }
