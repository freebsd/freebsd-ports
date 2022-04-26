--- src/Controller/Src/KeysValues/All/ScanHeightMax.cpp.orig	2021-11-25 00:56:58 UTC
+++ src/Controller/Src/KeysValues/All/ScanHeightMax.cpp
@@ -59,6 +59,8 @@ void ScanHeightMax::GetValue(SDIInt& intVal)
   case kSDIFunctionalUnitDocumentFeeder:
     intVal = ADFValue();
    return;
+  case kSDIFunctionalUnitCarrierSheet:
+   break;
  }
 }
 void ScanHeightMax::GetCapability(SDICapability &capability)
