--- src/Standalone/lengthdoublespinbox.cpp.orig	2021-11-25 00:56:57 UTC
+++ src/Standalone/lengthdoublespinbox.cpp
@@ -127,7 +127,7 @@ bool LengthDoubleSpinBox::isUnit_inchi(void)
     Units units = config.config_para.units;
     if(units == unit_inchi){
         return true;
-    }else if(units == unit_mm){
+    }else{
         return false;
     }
 }
