--- src/Standalone/detectionareamindoublespinbox.cpp.orig	2021-11-25 00:56:56 UTC
+++ src/Standalone/detectionareamindoublespinbox.cpp
@@ -100,7 +100,7 @@ bool DetectionAreaMinDoubleSpinBox::isUnit_inchi(void)
     Units units = config.config_para.units;
     if(units == unit_inchi){
         return true;
-    }else if(units == unit_mm){
+    }else{
         return false;
     }
 }
