--- src/Controller/Src/Filter/ProcOrientation.hpp.orig	2021-11-25 00:56:58 UTC
+++ src/Controller/Src/Filter/ProcOrientation.hpp
@@ -89,6 +89,7 @@ class ProcOrientation : public Filter (private)
    }
    break;
    case kSDIOrientationNone:
+   case kSDIOrientationAuto:
    break;
   }
   inDataBuf.FreeBuffer();
