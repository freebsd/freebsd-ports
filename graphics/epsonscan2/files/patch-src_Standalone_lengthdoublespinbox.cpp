--- src/Standalone/lengthdoublespinbox.cpp.orig	2024-09-12 07:10:42 UTC
+++ src/Standalone/lengthdoublespinbox.cpp
@@ -124,7 +124,7 @@ bool LengthDoubleSpinBox::isUnit_inchi(void)
     Units units = config.config_para.units;
     if(units == unit_inchi){
         return true;
-    }else if(units == unit_mm){
+    }else{
         return false;
     }
 }
