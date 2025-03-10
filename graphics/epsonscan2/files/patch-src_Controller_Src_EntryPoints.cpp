--- src/Controller/Src/EntryPoints.cpp.orig	2024-09-12 07:10:36 UTC
+++ src/Controller/Src/EntryPoints.cpp
@@ -343,6 +343,8 @@ SDIError SDIScannerDriver_GetNextTransferEvent(SDIScan
        }
       }
       break;
+      case kEventTypePaperJam:
+      break;
      }
      if (outError)
      {
