--- src/Controller/Src/KeysValues/All/ScanWidthMax.cpp.orig	2024-09-12 07:10:35 UTC
+++ src/Controller/Src/KeysValues/All/ScanWidthMax.cpp
@@ -55,6 +55,8 @@ void ScanWidthMax::GetValue(SDIInt& intVal)
   case kSDIFunctionalUnitDocumentFeeder:
     intVal = ADFValue();
    return;
+  case kSDIFunctionalUnitCarrierSheet:
+   break;
  }
 }
 void ScanWidthMax::GetCapability(SDICapability &capability)
