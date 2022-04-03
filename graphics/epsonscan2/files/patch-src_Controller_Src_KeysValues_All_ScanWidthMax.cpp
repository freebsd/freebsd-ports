--- src/Controller/Src/KeysValues/All/ScanWidthMax.cpp.orig	2021-11-25 00:56:58 UTC
+++ src/Controller/Src/KeysValues/All/ScanWidthMax.cpp
@@ -58,6 +58,8 @@ void ScanWidthMax::GetValue(SDIInt& intVal)
   case kSDIFunctionalUnitDocumentFeeder:
     intVal = ADFValue();
    return;
+  case kSDIFunctionalUnitCarrierSheet:
+   break;
  }
 }
 void ScanWidthMax::GetCapability(SDICapability &capability)
