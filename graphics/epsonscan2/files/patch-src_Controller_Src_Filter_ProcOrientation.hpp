--- src/Controller/Src/Filter/ProcOrientation.hpp.orig	2024-09-12 07:10:36 UTC
+++ src/Controller/Src/Filter/ProcOrientation.hpp
@@ -86,6 +86,7 @@ class ProcOrientation : public Filter (private)
    }
    break;
    case kSDIOrientationNone:
+   case kSDIOrientationAuto:
    break;
   }
   inDataBuf.FreeBuffer();
