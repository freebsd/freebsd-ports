--- src/Controller/Src/EntryPoints.cpp.orig	2021-11-25 00:56:59 UTC
+++ src/Controller/Src/EntryPoints.cpp
@@ -346,6 +346,8 @@ SDIError SDIScannerDriver_GetNextTransferEvent(SDIScan
        }
       }
       break;
+      case kEventTypePaperJam:
+      break;
      }
      if (outError)
      {
