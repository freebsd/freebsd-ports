--- src/Controller/Src/KeysValues/All/ScanHeightMax.cpp.orig	2024-09-12 07:10:35 UTC
+++ src/Controller/Src/KeysValues/All/ScanHeightMax.cpp
@@ -56,6 +56,8 @@ void ScanHeightMax::GetValue(SDIInt& intVal)
   case kSDIFunctionalUnitDocumentFeeder:
     intVal = ADFValue();
    return;
+  case kSDIFunctionalUnitCarrierSheet:
+   break;
  }
 }
 void ScanHeightMax::GetCapability(SDICapability &capability)
